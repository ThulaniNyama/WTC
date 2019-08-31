package com.mrb.swingy.view.start;

import com.mrb.swingy.Main;
import com.mrb.swingy.controller.StartController;
import com.mrb.swingy.view.create.CreateHeroViewGUI;
import com.mrb.swingy.view.select.SelectHeroViewGUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**

 */
public class StartViewGUI extends JPanel implements StartView {

    private JButton createHeroButton = new JButton("Create Hero");
    private JButton selectHeroButton = new JButton("Select Hero");
    private JButton switchViewButton = new JButton("Switch to console");

    private StartController controller;

    @Override
    public void start() {
        controller = new StartController(this);

        buildUI();
    }

    private void buildUI() {
        Main.getFrame().setTitle("Start");
        this.setLayout(new GridBagLayout());
        this.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(5, 5, 5, 5);

        this.add(createHeroButton, gbc);
        this.add(selectHeroButton, gbc);
        this.add(switchViewButton, gbc);

        this.setVisible(true);
        Main.getFrame().setContentPane(this);
        Main.getFrame().revalidate();
        Main.showFrame();

        createHeroButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.onCreateHeroButtonPressed();
            }
        });
        selectHeroButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.onSelectHeroButtonPressed();
            }
        });
        switchViewButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.onSwitchButtonPressed();
            }
        });
    }

    @Override
    public void openCreateHero() {
        this.setVisible(false);
        new CreateHeroViewGUI().start();
    }

    @Override
    public void switchView() {
        Main.hideFrame();
        new StartViewConsole().start();
    }

    @Override
    public void openSelectHero() {
        this.setVisible(false);
        new SelectHeroViewGUI().start();
    }
}
