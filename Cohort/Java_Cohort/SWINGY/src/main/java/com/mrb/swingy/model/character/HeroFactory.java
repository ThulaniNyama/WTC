package com.mrb.swingy.model.character;

/**

 */
public abstract class HeroFactory {

    public static Hero newHero(String name, String heroClass) {
        if ("HULK".equals(heroClass.toUpperCase())) {
            return Director.createHulk(name);
        } else if ("THOR".equals(heroClass.toUpperCase())) {
            return Director.createThor(name);
        } else if ("DR STRANGE".equals(heroClass.toUpperCase())) {
            return Director.createDrStrange(name);
        } else if ("CAPTAIN AMERICA".equals(heroClass.toUpperCase())) {
            return Director.createCaptainAmerica(name);
        } else if ("BLACK PANTHER".equals(heroClass.toUpperCase())) {
            return Director.createBlackPanther(name);
        } else if ("IRON MAN".equals(heroClass.toUpperCase())) {
            return Director.createIronMan(name);
        }
        throw new IllegalArgumentException("Invalid hero class: " + heroClass);
    }
}
