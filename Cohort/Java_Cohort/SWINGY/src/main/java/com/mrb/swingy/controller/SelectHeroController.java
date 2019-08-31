package com.mrb.swingy.controller;

import com.mrb.swingy.exception.HeroValidationException;
import com.mrb.swingy.model.Game;
import com.mrb.swingy.model.character.Hero;
import com.mrb.swingy.util.DataBase;
import com.mrb.swingy.view.select.SelectHeroView;

import java.util.ArrayList;

/**

 */
public class SelectHeroController {

    private SelectHeroView view;
    private Game game;

    public SelectHeroController(SelectHeroView view) {
        this.view = view;
        game = Game.getInstance();
    }

    public void onListElementSelected(int idx) {
        Hero hero = DataBase.selectHeroById(idx + 1);
        view.updateInfo(hero.toString());
    }

    public String[] getListData() {
        ArrayList<String> list = DataBase.selectAll();
        String[] listArr = new String[list.size()];
        listArr = list.toArray(listArr);
        return listArr;
    }

    public void onSelectButtonPressed(int idx) {
        Hero hero;
        try {
            hero = DataBase.selectHeroById(idx + 1);
            hero.validateHero();
        } catch (HeroValidationException e) {
            view.showErrorMessage(e.getMessage());
            return;
        }

        game.initGame(hero);
        view.openGame();
    }

    public void onExitButtonPressed() {
        System.exit(0);
    }

    public void onCreateButtonPressed() {
        view.openCreateHero();
    }
}
