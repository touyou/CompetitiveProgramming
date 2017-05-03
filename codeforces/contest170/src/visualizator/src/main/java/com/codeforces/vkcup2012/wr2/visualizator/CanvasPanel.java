package com.codeforces.vkcup2012.wr2.visualizator;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author edavtyan
 */
public class CanvasPanel extends JPanel {
    public static final String CHECKED_SUCCESSFULLY = "Solution has been successfully checked";
    private final int SHIFT_FOR_PADDING = 3;

    private int scale = 1;

    private final int maxWidth;
    private final int maxHeight;
    private int width;
    private int height;
    private List<Dimension> dimensions;
    private List<Rectangle> rectangles;
    private List<RawRectangle> rawRectangles;

    private String checkerMessage = " ";

    public String getCheckerMessage() {
        return checkerMessage;
    }

    public CanvasPanel(int maxWidth, int maxHeight) {
        super();

        this.maxWidth = maxWidth;
        this.maxHeight = maxHeight;

        this.width = maxWidth;
        this.height = maxHeight;

        setPreferredSize(new java.awt.Dimension(width + SHIFT_FOR_PADDING, height + SHIFT_FOR_PADDING));
        setBackground(Color.WHITE);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        if (dimensions != null && rectangles != null) {
            for (Rectangle rectangle : rectangles) {
                if (rectangle != null) {
                    drawRectangle(g, rectangle);
                }
            }
            
            for (int index1 = 0; index1 < rectangles.size(); index1++) {
                for (int index2 = index1 + 1; index2 < rectangles.size(); index2++) {
                    if (rectangles.get(index1) != null && rectangles.get(index2) != null) {
                        drawRectanglesIntersect(g, rectangles.get(index1), rectangles.get(index2));
                    }
                }
            }
        }
    }

    private void drawRectanglesIntersect(Graphics g, Rectangle rectangle1, Rectangle rectangle2) {
        if (accurateIntersect(rawRectangles.get(rectangle1.getIndex()), rawRectangles.get(rectangle2.getIndex()))) {
            int x1 = Math.max(rectangle1.getX(), rectangle2.getX());
            int x2 = Math.min(rectangle1.getX() + rectangle1.getWidth(), rectangle2.getX() + rectangle2.getWidth());
            int y1 = Math.max(rectangle1.getY(), rectangle2.getY());
            int y2 = Math.min(rectangle1.getY() + rectangle1.getHeight(), rectangle2.getY() + rectangle2.getHeight());
            
            if (rectangle1.isHorizontal() == rectangle2.isHorizontal()) {
                g.setColor(Color.RED);
            } else {
                g.setColor(new Color(0, 128, 0));
            }
            
            final int GAGE = 3;
            
            if (x1 == x2 && y1 <= y2) {
                g.fillRect(x1 - 1, y1, GAGE, y2 - y1 + 1);
            } else if (x1 <= x2 && y1 == y2) {
                g.fillRect(x1, y1 - 1, x2 - x1 + 1, GAGE);
            }
        }
    }

    private boolean accurateIntersect(RawRectangle rectangle1, RawRectangle rectangle2) {
        double x1 = Math.max(rectangle1.getX1(), rectangle2.getX1());
        double x2 = Math.min(rectangle1.getX2(), rectangle2.getX2());
        double y1 = Math.max(rectangle1.getY1(), rectangle2.getY1());
        double y2 = Math.min(rectangle1.getY2(), rectangle2.getY2());
        
        final double EPS = 1e-9;
        
        return x1 < x2 + EPS && y1 < y2 + EPS;
    }

    private void drawRectangle(Graphics g, Rectangle rectangle) {
        final int REGION_GAGE = 5;

        if (rectangle.isHorizontal()) {
            Color color = new Color(221, 238, 255);
            int regionCount = (rectangle.getHeight() + REGION_GAGE - 1) / REGION_GAGE;

            for (int index = 0; index < regionCount; index++) {
                int x = rectangle.getX();
                int y = rectangle.getY() + index * REGION_GAGE;
                int width = rectangle.getWidth();
                int height = index == regionCount - 1 ? (rectangle.getY() + rectangle.getHeight() - y) : REGION_GAGE;

                if (index % 2 == 0) {
                    g.setColor(color);
                } else {
                    g.setColor(Color.WHITE);
                }
                g.fillRect(x, y, width, height);
            }
        } else {
            Color color = new Color(255 - 5, 238 - 30, 221 - 50);
            int regionCount = (rectangle.getWidth() + REGION_GAGE - 1) / REGION_GAGE;

            for (int index = 0; index < regionCount; index++) {
                int x = rectangle.getX() + index * REGION_GAGE;
                int y = rectangle.getY();
                int width = index == regionCount - 1 ? (rectangle.getX() + rectangle.getWidth() - x) : REGION_GAGE;
                int height = rectangle.getHeight();

                if (index % 2 == 0) {
                    g.setColor(color);
                } else {
                    g.setColor(Color.WHITE);
                }
                g.fillRect(x, y, width, height);
            }
        }

        g.setColor(Color.BLACK);
        g.drawRect(rectangle.getX(), rectangle.getY(), rectangle.getWidth(), rectangle.getHeight());
    }

    public void setup(File inputFile, File outputFile) {
        try {
            parseDimensions(inputFile);
            parseRectangles(outputFile);
        } catch (Exception e) {
            dimensions = null;
            rectangles = null;
            checkerMessage = " ";
            changeSize(maxWidth, maxHeight);
        } finally {
            repaint();
        }
    }

    private void changeSize(int width, int height) {
        setLocation(getLocation().x + (this.width - width) / 2, getLocation().y + (this.height - height) / 2);
        this.width = width;
        this.height = height;
        setPreferredSize(new java.awt.Dimension(width + SHIFT_FOR_PADDING, height + SHIFT_FOR_PADDING));
        setSize(width + SHIFT_FOR_PADDING, height + SHIFT_FOR_PADDING);
    }

    private void parseDimensions(File file) throws FileNotFoundException {
        Scanner in = new Scanner(new FileReader(file));
        
        final int PADDING = 5;

        int width = in.nextInt();
        int height = in.nextInt();
        scale = Math.min((maxWidth - PADDING) / width, (maxHeight - PADDING) / height);
        changeSize(width * scale, height * scale);

        int rectanglesCount = in.nextInt();

        dimensions = new ArrayList<Dimension>(rectanglesCount);
        for (int index = 0; index < rectanglesCount; index++) {
            dimensions.add(new Dimension(in.nextInt(), in.nextInt()));
        }

        in.close();
    }

    @SuppressWarnings("UnusedDeclaration")
    private void parseRectangles(File file) throws FileNotFoundException {
        Scanner in = new Scanner(new FileReader(file));

        rectangles = new ArrayList<Rectangle>(dimensions.size());
        
        rawRectangles = new ArrayList<RawRectangle>(dimensions.size());
        
        for (int index = 0; index < dimensions.size(); index++) {
            Dimension dimension = dimensions.get(index);

            double x1 = in.nextDouble();
            double y1 = in.nextDouble();
            double x2 = in.nextDouble();
            double y2 = in.nextDouble();

            rawRectangles.add(new RawRectangle(x1, y1, x2, y2));
            
            if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
                rectangles.add(null);
            } else {
                double k1 = ((double) dimension.getWidth()) / dimension.getHeight();
                double k2 = Math.abs(x2 - x1) / Math.abs(y2 - y1);

                rectangles.add(new Rectangle(
                        scaleAndRound(x1), height - scaleAndRound(y1), scaleAndRound(x2), height - scaleAndRound(y2),
                        Math.abs(k1 - k2) < 1e-9, index));
            }
        }
        
        List<Integer> widths = new ArrayList<Integer>(dimensions.size());
        List<Integer> heights = new ArrayList<Integer>(dimensions.size());
        for (Dimension dimension : dimensions) {
            widths.add(dimension.getWidth());
            heights.add(dimension.getHeight());
        }

        try {
            double points = Checker.getInstance().check(width, height, widths, heights, rawRectangles);
            checkerMessage = CHECKED_SUCCESSFULLY + " for " + points + " points";
        } catch (CheckerException e) {
            checkerMessage = e.getMessage();
        }

        in.close();
    }

    private int scaleAndRound(double a) {
        return (int) (a * scale + 0.5);
    }

    public int getRectangleIndex(int x, int y) {
        if (rectangles != null) {
            for (Rectangle rectangle : rectangles) {
                if (rectangle != null &&
                        rectangle.getX() <= x && x <= rectangle.getX() + rectangle.getWidth() &&
                        rectangle.getY() <= y && y <= rectangle.getY() + rectangle.getHeight()) {
                    return rectangle.getIndex();
                }
            }
        }
        return -1;
    }

    private static class Rectangle {
        private final int x;
        private final int y;
        private final int width;
        private final int height;
        private final boolean horizontal;
        private final int index;

        private Rectangle(int x1, int y1, int x2, int y2, boolean horizontal, int index) {
            x = Math.min(x1, x2) + 1;
            y = Math.min(y1, y2) + 1;
            width = Math.max(x1, x2) - Math.min(x1, x2);
            height = Math.max(y1, y2) - Math.min(y1, y2);
            this.horizontal = horizontal;
            this.index = index;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public int getWidth() {
            return width;
        }

        public int getHeight() {
            return height;
        }

        public int getIndex() {
            return index;
        }

        public boolean isHorizontal() {
            return horizontal;
        }
    }
    
    public static class RawRectangle {
        private final double x1;
        private final double y1;
        private final double x2;
        private final double y2;

        private RawRectangle(double x1, double y1, double x2, double y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public double getX1() {
            return x1;
        }

        public double getY1() {
            return y1;
        }

        public double getX2() {
            return x2;
        }

        public double getY2() {
            return y2;
        }
    }
    
    private static class Dimension {
        private final int width;
        private final int height;

        private Dimension(int width, int height) {
            this.width = width;
            this.height = height;
        }

        public int getWidth() {
            return width;
        }

        public int getHeight() {
            return height;
        }
    }
}
