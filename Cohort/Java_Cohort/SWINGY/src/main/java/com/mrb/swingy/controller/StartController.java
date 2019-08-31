package com.mrb.swingy.controller;

import com.mrb.swingy.view.start.StartView;

/**
 */
public class StartController {

    private StartView view;

    public StartController(StartView view) {
        this.view = view;
    }

    public void onCreateHeroButtonPressed() {
        view.openCreateHero();
    }

    public void onSwitchButtonPressed() {
        view.switchView();
    }

    public void onSelectHeroButtonPressed() {
        view.openSelectHero();
    }

    public void onExitButtonPressed() {
        System.exit(0);
    }
}
