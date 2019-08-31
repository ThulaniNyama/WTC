package com.mrb.swingy.view.create;

import com.mrb.swingy.Main;
import com.mrb.swingy.controller.CreateHeroController;
import com.mrb.swingy.view.game.GameViewConsole;

import java.util.Scanner;

/**

 */
public class CreateHeroViewConsole implements CreateHeroView {

    private CreateHeroController controller;

    @Override
    public void start() {
        controller = new CreateHeroController(this);

        getUserInput();
    }

    @Override
    public void getUserInput() {
        Scanner scanner = Main.getScanner();

        System.out.println("To create hero enter his name and class.");
        System.out.print("Enter name: ");
        String name = scanner.nextLine();
        if (name.equalsIgnoreCase("exit")) {
            getUserInput();
        } else {
            System.out.print("Classes: attack  defense   hp\n" +
                    "Hulk              40      15      95\n" +
                    "Thor              50      25      120\n" +
                "Dr Strange        25      30      70\n" +
                    "Captain America   35      25      110\n" +
                    "Black Panther     30      20      100\n" +
                    "Iron Man          35      25      105\n\n" +
                    "Enter class hero: ");
            String heroClass = scanner.nextLine();

            System.out.println("CONFIRM - to confirm hero with previously entered Name and Class");
            System.out.println("EXIT - to exit game");
            System.out.print("Command (CONFIRM) or (EXIT):");
            while (scanner.hasNext()) {
                String input = scanner.nextLine();
                if ("confirm".equalsIgnoreCase(input)) {
                    controller.onCreateButtonPressed(name, heroClass);
                    break;
                }
                else if ("exit".equalsIgnoreCase(input)){
                    controller.onExitButtonPressed();
                    break;
                } else {
                    System.out.println("Unknown command!!!");
                }
            }
        }
    }

    @Override
    public void showErrorMessage(String message) {
        System.out.println("Error: " + message);
    }

    @Override
    public void openGame() {
        new GameViewConsole().start();
    }
}
