package com.mrb.swingy.view.select;

import com.mrb.swingy.Main;
import com.mrb.swingy.controller.SelectHeroController;
import com.mrb.swingy.view.create.CreateHeroViewConsole;
import com.mrb.swingy.view.game.GameViewConsole;

import java.util.Scanner;

/**

 */
public class SelectHeroViewConsole implements SelectHeroView {

    private SelectHeroController controller;
    private int lastIdx = -1;

    @Override
    public void start() {
        controller = new SelectHeroController(this);

        getInput();
    }

    private void getInput() {
        Scanner scanner = Main.getScanner();

        System.out.println("Available heroes: ");
        printHeroes(controller.getListData());

        System.out.println();
        System.out.println("CREATE - to create hero");
        System.out.println("NUMBER - enter number of available hero to see full information");
        System.out.println("SELECT - enter select after entering number");
        System.out.print("Commands (CREATE, NUMBER, SELECT, EXIT): ");
        while (scanner.hasNext()) {
            String input = scanner.nextLine();

            if ("create".equalsIgnoreCase(input)) {
                controller.onCreateButtonPressed();
                break;
            } else if (isValidNumericString(input, controller.getListData().length)) {
                lastIdx = Integer.parseInt(input) - 1;
                controller.onListElementSelected(lastIdx);
            } else if ("select".equalsIgnoreCase(input) && lastIdx != -1) {
                controller.onSelectButtonPressed(lastIdx);
                break;
            } else if ("exit".equalsIgnoreCase(input)){
                controller.onExitButtonPressed();
            } else {
                System.out.println("Unknown command");
            }
        }
    }

    private boolean isValidNumericString(String str, int max) {
        try {
            int n = Integer.parseInt(str);
            if (n <= 0 || n > max)
                return false;
        } catch (NumberFormatException e) {
            return false;
        }
        return true;
    }

    private void printHeroes(String[] heroes) {
        if (heroes.length == 0)
            System.out.println("No saved heroes");
        for (String hero : heroes) {
            System.out.println(hero);
        }
    }

    @Override
    public void updateInfo(String info) {
        System.out.println(info);
    }

    @Override
    public void showErrorMessage(String message) {
        System.out.println("Error: " + message);
        getInput();
    }

    @Override
    public void openGame() {
        new GameViewConsole().start();
    }

    @Override
    public void openCreateHero() {
        new CreateHeroViewConsole().start();
    }
}
