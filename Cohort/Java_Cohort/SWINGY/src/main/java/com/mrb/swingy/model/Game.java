package com.mrb.swingy.model;

import com.mrb.swingy.model.artifact.Armor;
import com.mrb.swingy.model.artifact.Artifact;
import com.mrb.swingy.model.artifact.Helm;
import com.mrb.swingy.model.artifact.Weapon;
import com.mrb.swingy.model.character.Character;
import com.mrb.swingy.model.character.Hero;
import com.mrb.swingy.model.character.Villain;
import com.mrb.swingy.util.Point;

import java.util.concurrent.ThreadLocalRandom;

/**

 */
public class Game {

    private static Game instance = null;

    private Hero hero;
    private Point heroCoord;
    private int mapSize;
    private boolean[][] map;

    private Game() {
    }

    public static Game getInstance() {
        if (instance == null) {
            instance = new Game();
        }
        return instance;
    }

    public void initGame(Hero hero) {
        this.hero = hero;
        generateMap();
        generateVillains();
        putHero();
    }

    private void generateMap() {
        int level = hero.getLevel();
        mapSize = (level - 1) * 5 + 10 - (level % 2);
        map = new boolean[mapSize][mapSize];
    }

    private void generateVillains() {
        int rand;
        int level = hero.getLevel();

        for (int i = 0; i < mapSize; i++) {
            for (int j = 0; j < mapSize; j++) {
                rand = ThreadLocalRandom.current().nextInt(0, 101);
                if ((level + 1) * 10 >= rand)
                    map[i][j] = true;
            }
        }
    }

    public Villain generateVillain() {
        int attack = ThreadLocalRandom.current().nextInt(hero.getAttack() - 20, hero.getAttack() + 2 + hero.getLevel());
        int defense = ThreadLocalRandom.current().nextInt(hero.getDefense() - 20, hero.getDefense() + 2 + hero.getLevel());
        int hitPoints = ThreadLocalRandom.current().nextInt(hero.getHitPoints() - 50, hero.getHitPoints() + 20 + hero.getLevel());

        attack = attack < 0 ? -attack : attack;
        defense = defense < 0 ? -defense : defense;
        hitPoints = hitPoints < 0 ? -hitPoints : hitPoints;
        Artifact artifact = generateArtifact();

        return new Villain("Villain", attack, defense, hitPoints, artifact);
    }

    private Artifact generateArtifact() {
        int rand = ThreadLocalRandom.current().nextInt(0, 10);

        Artifact artifact = null;
        if (rand == 0)
            artifact = new Weapon("Sword", ThreadLocalRandom.current().nextInt(1, 5 * (hero.getLevel() + 1)));
        else if (rand == 1)
            artifact = new Helm("Pot", ThreadLocalRandom.current().nextInt(1, 3 * (hero.getLevel() + 1)));
        else if (rand == 2)
            artifact = new Armor("Shield", ThreadLocalRandom.current().nextInt(1, 4 * (hero.getLevel() + 1)));
        return artifact;
    }

    public int fightResult(Character villain) {
        int xp = villain.getAttack() + villain.getDefense() + villain.getHitPoints();
        int rand = ThreadLocalRandom.current().nextInt(0, 101);

        if (rand < 3)
            return xp;
        else if (rand > 98)
            return -1;

        return hero.fight(villain) ? xp : -1;
    }

    private void putHero() {
        heroCoord = new Point(mapSize / 2, mapSize / 2);
        map[heroCoord.getY()][heroCoord.getX()] = false;
    }

    public int getMapSize() {
        return mapSize;
    }

    public void setMapSize(int mapSize) {
        this.mapSize = mapSize;
    }

    public Hero getHero() {
        return hero;
    }

    public void setHero(Hero hero) {
        this.hero = hero;
    }

    public Point getHeroCoord() {
        return heroCoord;
    }

    public void setHeroCoord(Point heroCoord) {
        this.heroCoord = heroCoord;
    }

    public boolean[][] getMap() {
        return map;
    }

    public void setMap(boolean[][] map) {
        this.map = map;
    }
}
