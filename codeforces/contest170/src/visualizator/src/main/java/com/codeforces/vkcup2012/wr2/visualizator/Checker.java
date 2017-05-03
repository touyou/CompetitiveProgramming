package com.codeforces.vkcup2012.wr2.visualizator;

import java.util.ArrayList;
import java.util.List;

/**
 * @author edavtyan
 */
public class Checker {
    private final double SCALE = 10;

    private final static Checker INSTANCE = new Checker();

    private Checker() {
    }

    public static Checker getInstance() {
        return INSTANCE;
    }

    private boolean same(double a, double b) {
        return Math.abs(a - b) < 1e-10;
    }

    private int roundScaled(double d) throws CheckerException {
        if (d < 0 || d > 1E9 / SCALE) {
            throw new CheckerException(String.format("Number is out of range: %.10f", d));
        }

        return (int) (d * SCALE + 0.5);
    }

    private boolean isRound(double d) throws CheckerException {
        return same(d * SCALE, roundScaled(d));
    }

    public double check(int width, int height, List<Integer> widths, List<Integer> heights,
                        List<CanvasPanel.RawRectangle> rectangles) throws CheckerException {
        width = roundScaled(width);
        height = roundScaled(height);

        for (int i = 0; i < rectangles.size(); i++) {
            widths.set(i, roundScaled(widths.get(i)));
            heights.set(i, roundScaled(heights.get(i)));
        }
        
        List<Integer> left = new ArrayList<Integer>();
        List<Integer> right = new ArrayList<Integer>();
        List<Integer> bottom = new ArrayList<Integer>();
        List<Integer> top = new ArrayList<Integer>();
        List<Integer> type = new ArrayList<Integer>();

        for (int index = 0; index < rectangles.size(); index++) {
            CanvasPanel.RawRectangle rectangle = rectangles.get(index);

            double x1 = rectangle.getX1();
            double y1 = rectangle.getY1();
            double x2 = rectangle.getX2();
            double y2 = rectangle.getY2();

            if (same(x1, -1.0) && same(y1, -1) && same(x2, -1) && same(y2, -1)) {
                left.add(-1);
                bottom.add(-1);
                right.add(-1);
                top.add(-1);
                type.add(-1);
                continue;
            }

            if (x1 > x2) {
                double tmp = x1;
                x1 = x2;
                x2 = tmp;
            }

            if (y1 > y2) {
                double tmp = y1;
                y1 = y2;
                y2 = tmp;
            }

            if (!isRound(x1) || !isRound(y1) || !isRound(x2) || !isRound(y2)) {
                throw new CheckerException("Coordinates of the rectangle #%d have invalid precision");
            }

            int x1Rounded = roundScaled(x1);
            int y1Rounded = roundScaled(y1);
            int x2Rounded = roundScaled(x2);
            int y2Rounded = roundScaled(y2);

            left.add(x1Rounded);
            bottom.add(y1Rounded);
            right.add(x2Rounded);
            top.add(y2Rounded);

            if (x1Rounded < 0 || x1Rounded > width || y1Rounded < 0 || y1Rounded > height
                    || x2Rounded < 0 || x2Rounded > width || y2Rounded < 0 || y2Rounded > height) {
                throw new CheckerException(String.format("Coordinates of the rectangle #%d are out of range", index + 1));
            }

            if (x1Rounded == x2Rounded || y1Rounded == y2Rounded) {
                throw new CheckerException(String.format("Rectangle #%d has zero size", index + 1));
            }

            double scale = (x2 - x1) / (y2 - y1);
            double expectedScale = (double)(widths.get(index)) / (double)(heights.get(index));

            int dx, dy;

            if (same(expectedScale, scale)) {
                dx = x2Rounded - x1Rounded;
                dy = y2Rounded - y1Rounded;
                type.add(0);
            } else {
                scale = 1.0 / scale;
                if (!same(expectedScale, scale)) {
                    throw new CheckerException(String.format("Rectangle #%d is not scaled", index + 1));
                }

                dx = y2Rounded - y1Rounded;
                dy = x2Rounded - x1Rounded;
                type.add(1);
            }

            if (dx > 2 * widths.get(index) || dx * 10 < widths.get(index)) {
                throw new CheckerException(String.format("Rectangle #%d illegal scale (width)", index + 1));
            }

            if (dy > 2 * heights.get(index) || dy * 10 < heights.get(index)) {
                throw new CheckerException(String.format("Rectangle #%d illegal scale (height)", index + 1));
            }
        }

        int result = 0;

        for (int i = 0; i < rectangles.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (type.get(i) == -1 || type.get(j) == -1)
                    continue;

                int x1 = Math.max(left.get(i), left.get(j));
                int x2 = Math.min(right.get(i), right.get(j));

                int y1 = Math.max(bottom.get(i), bottom.get(j));
                int y2 = Math.min(top.get(i), top.get(j));

                if (x1 < x2 && y1 < y2) {
                    throw new CheckerException(String.format("Rectangles #%d and #%d are intersect", i + 1, j + 1));
                }

                if (x1 < x2 && y1 == y2) {
                    result += (type.get(i).equals(type.get(j)) ? -1 : 1) * (x2 - x1);
                }

                if (y1 < y2 && x1 == x2) {
                    result += (type.get(i).equals(type.get(j)) ? -1 : 1) * (y2 - y1);
                }
            }
        }

        return ((double) result) / 10;
    }
}
