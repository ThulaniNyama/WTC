package com.mrb.swingy.model.character;

/**
 *
 */
public class Director {

    private static HeroBuilder buildNew(String name) {
        HeroBuilder builder = new HeroBuilder();
        builder.setName(name);
        builder.setLevel(0);
        builder.setExperience(0);
        return builder;
    }

    public static Hero createHulk(String name) {
        HeroBuilder builder = buildNew(name);
        builder.setAttack(40);
        builder.setDefense(20);
        builder.setHitPoints(100);
        builder.setHeroClass("Hulk");
        return builder.getHero();
    }

    public static Hero createThor(String name) {
        HeroBuilder builder = buildNew(name);
        builder.setAttack(30);
        builder.setDefense(15);
        builder.setHitPoints(90);
        builder.setHeroClass("Thor");
        return builder.getHero();
    }

    public static Hero createDrStrange(String name) {
        HeroBuilder builder = buildNew(name);
        builder.setAttack(25);
        builder.setDefense(25);
        builder.setHitPoints(90);
        builder.setHeroClass("Dr Strange");
        return builder.getHero();
    }

    public static Hero createCaptainAmerica(String name) {
        HeroBuilder builder = buildNew(name);
        builder.setAttack(40);
        builder.setDefense(30);
        builder.setHitPoints(120);
        builder.setHeroClass("Captain America");
        return builder.getHero();
    }

    public static Hero createBlackPanther(String name) {
        HeroBuilder builder = buildNew(name);
        builder.setAttack(45);
        builder.setDefense(10);
        builder.setHitPoints(80);
        builder.setHeroClass("Black Panther");
        return builder.getHero();
    }

    public static Hero createIronMan(String name) {
        HeroBuilder builder = buildNew(name);
        builder.setAttack(25);
        builder.setDefense(20);
        builder.setHitPoints(110);
        builder.setHeroClass("Iron Man");
        return builder.getHero();
    }
}
