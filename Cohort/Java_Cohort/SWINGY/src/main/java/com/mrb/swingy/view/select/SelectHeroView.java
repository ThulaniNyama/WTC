package com.mrb.swingy.view.select;

/**
 *
 */
public interface SelectHeroView {

    void start();

    void updateInfo(String info);

    void showErrorMessage(String message);

    void openGame();

    void openCreateHero();
}
