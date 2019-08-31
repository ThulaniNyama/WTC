package com.mrb.swingy.view.game;

import com.mrb.swingy.Main;
import com.mrb.swingy.controller.GameController;
import com.mrb.swingy.model.Game;
import com.mrb.swingy.util.Point;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**

 */
public class GameViewGUI extends JPanel implements GameView {

    private String[] directions = {"North", "East", "South", "West"};
    private JComboBox<String> directionsComboBox = new JComboBox<>(directions);
    private JButton moveButton = new JButton("Move");
    private JButton switchButton = new JButton("Switch to console");

    private JEditorPane infoPane = new JEditorPane();
    private JEditorPane mapPane = new JEditorPane();

    private GameController controller;

    @Override
    public void start() {
        controller = new GameController(this);

        buildUI();
        controller.onStart();
    }

    private void buildUI() {
        Main.getFrame().setTitle("Game");
        this.setLayout(new GridBagLayout());
        this.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        gbc.fill = GridBagConstraints.HORIZONTAL;

        infoPane.setEditable(false);
        infoPane.setText("Select hero to see information");
        infoPane.setPreferredSize(new Dimension(220, 190));
        infoPane.setMinimumSize(new Dimension(200, 200));
        this.add(infoPane, gbc);
        gbc.insets = new Insets(5, 5, 5, 5);

        mapPane.setEditable(false);
        mapPane.setText("Map");
        JScrollPane mapScroll = new JScrollPane(mapPane);
        mapScroll.setPreferredSize(new Dimension(300, 300));
        mapScroll.setMinimumSize(new Dimension(200, 200));

        directionsComboBox.setSelectedIndex(0);
        this.add(directionsComboBox, gbc);
        this.add(moveButton, gbc);
        this.add(switchButton, gbc);

        this.setVisible(true);
        Main.getFrame().setContentPane(this);
        Main.getFrame().revalidate();
        Main.showFrame();

        moveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.onMove((String) directionsComboBox.getSelectedItem());
            }
        });
        switchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.onSwitchButtonPressed();
            }
        });
    }

    @Override
    public void printMap(boolean[][] map, Point heroCoord) {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(String.format("MAP %dx%d\n", map.length, map.length));
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                if (heroCoord.getX() == j && heroCoord.getY() == i)
                    stringBuilder.append("! ");
                else if (map[i][j])
                    stringBuilder.append("* ");
                else
                    stringBuilder.append(". ");
            }
            stringBuilder.append("\n");
        }
        mapPane.setText(stringBuilder.toString());
    }

    @Override
    public void update(Game game) {
        infoPane.setText(game.getHero().toString() +
                "Position: " + "(" + game.getHeroCoord().getX() +
                "," + game.getHeroCoord().getY() + ")");

        printMap(game.getMap(), game.getHeroCoord());
    }

    @Override
    public void gameFinished() {
        Main.hideFrame();
        Main.getFrame().dispose();
        Main.closeConnections();
    }

    @Override
    public void showMessage(String message) {
        JOptionPane.showMessageDialog(Main.getFrame(), message);
    }

    @Override
    public void getVillainCollisionInput() {
        Object options[] = {"Fight", "Run"};

        int result = JOptionPane.showOptionDialog(Main.getFrame(),
                "You moved to position occupied by villain",
                "Fight or run?", JOptionPane.YES_NO_OPTION,
                JOptionPane.QUESTION_MESSAGE, null, options, options[0]);
        if (result == JOptionPane.YES_OPTION)
            controller.onFight();
        else
            controller.onRun();
    }

    @Override
    public boolean replaceArtifact(String replaceMessage) {
        Object options[] = {"Replace", "Leave"};

        int result = JOptionPane.showOptionDialog(Main.getFrame(),
                "Would you like to replace " + replaceMessage + "?",
                "Replace or leave?", JOptionPane.YES_NO_OPTION,
                JOptionPane.QUESTION_MESSAGE, null, options, options[0]);
        return result == JOptionPane.YES_OPTION;
    }

    @Override
    public void switchView() {
        Main.hideFrame();
        new GameViewConsole().start();
    }
}
