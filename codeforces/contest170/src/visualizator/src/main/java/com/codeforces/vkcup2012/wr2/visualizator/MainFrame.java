package com.codeforces.vkcup2012.wr2.visualizator;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.util.Locale;

/**
 * @author edavtyan
 */
public class MainFrame extends JFrame {
    public static final int MAIN_FRAME_WIDTH = 960;
    public static final int MAIN_FRAME_HEIGHT = 705;

    public static final int TEXT_FIELD_WIDTH = 384;
    public static final int TEXT_FIELD_HEIGHT = 26;

    private final JFileChooser fileChooser = new JFileChooser(new File(".").getAbsolutePath());
    private final JTextField inputFileNameTextField = new JTextField();
    private final JTextField outputFileNameTextField = new JTextField();
    private final JButton inputFileOpenButton = new JButton();
    private final JButton outputFileOpenButton = new JButton();
    private final JLabel checkerMessageLabel = new JLabel(" ");
    private final CanvasPanel canvasPanel = new CanvasPanel(MAIN_FRAME_WIDTH - 10, MAIN_FRAME_HEIGHT - 136) {
        @Override
        public JToolTip createToolTip() {
            JToolTip toolTip = new JToolTip();
            toolTip.setComponent(this);
            return toolTip;
        }
    };

    public MainFrame(String title) throws HeadlessException {
        super(title);

        // size
        setSize(MAIN_FRAME_WIDTH, MAIN_FRAME_HEIGHT);

        // location
        Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (dimension.width - getSize().width) / 2;
        int y = (dimension.height - getSize().height) / 2;
        setLocation(x, y);

        // other settings
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        addComponents();
    }

    private void addComponents() {
        add(createFilesOpenPanelWithButton());
        add(createCanvasPanel());
    }

    private JComponent createFilesOpenPanelWithButton() {
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        panel.add(createFilesOpenPanel());
        panel.add(createCheckerMessagePanel());

        return panel;
    }

    private JComponent createCheckerMessagePanel() {
        JPanel panel = new JPanel(new FlowLayout());
        panel.add(checkerMessageLabel);
        return panel;
    }

    private JComponent createFileOpenPanel(String title, JTextField textField, JButton button) {
        JPanel panel = new JPanel(new FlowLayout());
        panel.setBorder(BorderFactory.createTitledBorder(title));

        textField.setPreferredSize(new Dimension(TEXT_FIELD_WIDTH, TEXT_FIELD_HEIGHT));
        textField.getDocument().addDocumentListener(new DocumentListener() {
            public void insertUpdate(DocumentEvent e) {
                updateCanvas();
            }

            public void removeUpdate(DocumentEvent e) {
                updateCanvas();
            }

            public void changedUpdate(DocumentEvent e) {
                updateCanvas();
            }
        });
        panel.add(textField);

        button.setText("Open");
        button.addActionListener(new FileOpenActionListener(textField));
         panel.add(button);

        return panel;
    }

    private void updateCanvas() {
        File inputFile;
        File outputFile;

        try {
            inputFile = new File(inputFileNameTextField.getText());
            outputFile = new File(outputFileNameTextField.getText());
        } catch (Exception e) {
            return;
        }

        canvasPanel.setup(inputFile, outputFile);
        checkerMessageLabel.setText(canvasPanel.getCheckerMessage());
    }

    private JComponent createFilesOpenPanel() {
        JPanel panel = new JPanel();

        panel.add(createFileOpenPanel("Input file", inputFileNameTextField, inputFileOpenButton));
        panel.add(createFileOpenPanel("Output file", outputFileNameTextField, outputFileOpenButton));

        return panel;
    }

    private JComponent createCanvasPanel() {
        canvasPanel.setBorder(BorderFactory.createTitledBorder(""));

        final MouseAdapter mouseAdapter = new MouseAdapterForToolTip(canvasPanel);

        canvasPanel.addMouseMotionListener(mouseAdapter);
        canvasPanel.addMouseListener(mouseAdapter);

        return canvasPanel;
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        final MainFrame mainFrame = new MainFrame("VK Cup 2012 Wild-card Round 2 - Placing Rectangles");
        setupCommandLineParameters(mainFrame, args);
        mainFrame.setVisible(true);
        new Timer(1000, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                mainFrame.updateCanvas();
            }
        }).start();
    }

    private static void setupCommandLineParameters(final MainFrame frame, String[] args) {
        if (args.length == 2) {
            final File inputFile = new File(args[0]);
            final File outputFile = new File(args[1]);

            if (inputFile.exists() && outputFile.exists()) {
                frame.addComponentListener(new ComponentAdapter() {
                    @Override
                    public void componentShown(ComponentEvent e) {
                        frame.inputFileNameTextField.setText(inputFile.getAbsolutePath());
                        frame.outputFileNameTextField.setText(outputFile.getAbsolutePath());
                    }
                });
            }
        }
    }

    private class FileOpenActionListener implements ActionListener {
        private final JTextField textField;

        private FileOpenActionListener(JTextField textField) {
            this.textField = textField;
        }

        public void actionPerformed(ActionEvent e) {
            fileChooser.showOpenDialog(textField);

            File file = fileChooser.getSelectedFile();
            if (file != null) {
                fileChooser.setCurrentDirectory(file.getParentFile());
                textField.setText(file.getAbsolutePath());
            }
        }
    }

    private static class MouseAdapterForToolTip extends MouseAdapter {
        private final int DELAY = 500;
        
        private final CanvasPanel component;
        private final JToolTip toolTip = new JToolTip();
        private Popup lastPopup;
        private Point lastPoint;

        private final Timer timer = new Timer(DELAY, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int rectangleIndex = lastPoint == null ? -1 : component.getRectangleIndex(lastPoint.x, lastPoint.y);
                if (rectangleIndex == -1) {
                    hideLastPopup();
                    return;
                }
                toolTip.setTipText("Rectangle #" + (rectangleIndex + 1));

                SwingUtilities.convertPointToScreen(lastPoint, component);

                Popup newPopup = PopupFactory.getSharedInstance().getPopup(component, toolTip, lastPoint.x, lastPoint.y + 21);
                hideLastPopup();
                lastPopup = newPopup;

                newPopup.show();

                timer.stop();
            }
        });

        public MouseAdapterForToolTip(CanvasPanel component) {
            this.component = component;
        }

        @Override
        public void mouseMoved(MouseEvent e) {
            lastPoint = e.getPoint();

            timer.setDelay(DELAY);
            timer.start();

            hideLastPopup();
        }

        @Override
        public void mouseExited(MouseEvent e) {
            hideLastPopup();
            timer.stop();
        }

        private void hideLastPopup() {
            if (lastPopup != null) {
                lastPopup.hide();
                lastPopup = null;
            }
        }
    }
}
