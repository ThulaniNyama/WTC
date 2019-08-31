package com.mrb.swingy.view.select;

import com.mrb.swingy.Main;
import com.mrb.swingy.controller.SelectHeroController;
import com.mrb.swingy.view.create.CreateHeroViewGUI;
import com.mrb.swingy.view.game.GameViewGUI;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**

 */
public class SelectHeroViewGUI extends JPanel implements SelectHeroView {

    private JEditorPane infoPane = new JEditorPane();
    private JButton selectButton = new JButton("Select");
    private JButton createButton = new JButton("Create");

    private SelectHeroController controller;
    private int lastSelectedIdx;

    @Override
    public void start() {
        controller = new SelectHeroController(this);

        buildUI();
    }

    private void buildUI() {
        Main.getFrame().setTitle("Select Hero");
        this.setLayout(new GridBagLayout());
        this.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridwidth = GridBagConstraints.REMAINDER;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(5, 5, 5, 5);

        String[] data = controller.getListData();
        final JList list = new JList(data);
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.setLayoutOrientation(JList.VERTICAL);
        list.setVisibleRowCount(-1);
        JScrollPane listScroll = new JScrollPane(list);
        listScroll.setPreferredSize(new Dimension(200, 200));
        listScroll.setMinimumSize(new Dimension(150, 150));
        this.add(listScroll);

        infoPane.setEditable(false);
        infoPane.setText("Select hero to see information");
        if (data.length == 0)
            infoPane.setText("No saved heroes");
        JScrollPane infoScroll = new JScrollPane(infoPane);
        infoScroll.setPreferredSize(new Dimension(200, 200));
        infoScroll.setMinimumSize(new Dimension(150, 150));
        this.add(infoScroll, gbc);

        this.add(selectButton, gbc);
        this.add(createButton, gbc);
        selectButton.setEnabled(false);

        this.setVisible(true);

        Main.getFrame().setContentPane(this);
        Main.getFrame().revalidate();
        Main.showFrame();

        list.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    if (list.getSelectedIndex() != -1) {
                        controller.onListElementSelected(list.getSelectedIndex());
                        selectButton.setEnabled(true);
                        lastSelectedIdx = list.getSelectedIndex();
                    } else
                        selectButton.setEnabled(false);
                }
            }
        });
        selectButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.onSelectButtonPressed(lastSelectedIdx);
            }
        });
        createButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.onCreateButtonPressed();
            }
        });
    }

    @Override
    public void updateInfo(String info) {
        infoPane.setText(info);
    }

    @Override
    public void showErrorMessage(String message) {
        JOptionPane.showMessageDialog(Main.getFrame(), message);
    }

    @Override
    public void openGame() {
        this.setVisible(false);
        new GameViewGUI().start();
    }

    @Override
    public void openCreateHero() {
        this.setVisible(false);
        new CreateHeroViewGUI().start();
    }
}
