package com.mrb.swingy.model.character;

import com.mrb.swingy.exception.HeroValidationException;
import com.mrb.swingy.model.artifact.Armor;
import com.mrb.swingy.model.artifact.Helm;
import com.mrb.swingy.model.artifact.Weapon;

import javax.validation.*;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import java.util.Set;
import java.util.logging.Level;

/**

 */
public class Hero extends Character {

    private Weapon weapon;
    private Armor armor;
    private Helm helm;

    @Min(value = 0, message = "Level must not be less than 0")
    private int level;

    @Min(value = 0, message = "Experience must not be less than 0")
    private int experience;

    @NotNull(message = "Hero class must not be empty")
    private String heroClass;

    private int id;

    public Hero(String name, int attack, int defense, int hitPoints, int id, String heroClass,
                int level, int experience, Weapon weapon, Armor armor, Helm helm) {
        super(name, attack, defense, hitPoints);
        this.id = id;
        this.weapon = weapon;
        this.armor = armor;
        this.helm = helm;
        this.level = level;
        this.experience = experience;
        this.heroClass = heroClass;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void validateHero() throws HeroValidationException {
        java.util.logging.Logger.getLogger("org.hibernate").setLevel(Level.OFF);
        ValidatorFactory factory = Validation.buildDefaultValidatorFactory();
        Validator validator = factory.getValidator();

        Set<ConstraintViolation<Hero>> constraintViolations = validator.validate(this);
        if (constraintViolations.size() != 0) {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append("Hero validation error(s): ");
            stringBuilder.append(constraintViolations.size());
            stringBuilder.append("\n");
            for (ConstraintViolation<Hero> cv : constraintViolations) {
                stringBuilder.append("property: [");
                stringBuilder.append(cv.getPropertyPath());
                stringBuilder.append("], value: [");
                stringBuilder.append(cv.getInvalidValue());
                stringBuilder.append("], message: [");
                stringBuilder.append(cv.getMessage());
                stringBuilder.append("]\n");
            }
            throw new HeroValidationException(stringBuilder.toString());
        }
    }

    public void equipWeapon(Weapon weapon) {
        if (this.weapon != null) {
            this.attack -= this.weapon.getPoints();
        }
        this.attack += weapon.getPoints();
        this.weapon = weapon;
    }

    public void equipHelm(Helm helm) {
        if (this.helm != null) {
            this.hitPoints -= this.helm.getPoints();
            if (this.hitPoints + helm.getPoints() <= 0) {
                this.hitPoints += this.helm.getPoints();
                return;
            }
        }
        this.hitPoints += helm.getPoints();
        this.helm = helm;
    }

    public void equipArmor(Armor armor) {
        if (this.armor != null) {
            this.defense -= this.armor.getPoints();
        }
        this.defense += armor.getPoints();
        this.armor = armor;
    }

    public void addExperience(int addXP) {
        int nextLevel = (level + 1) * 1000 + level * level * 450;

        if (experience + addXP >= nextLevel)
            levelUp();
        experience += addXP;
    }

    private void levelUp() {
        level++;
        hitPoints += 50 + level * 10;
        attack += level * 3;
        defense += level * 2;
    }

    public Weapon getWeapon() {
        return weapon;
    }

    public void setWeapon(Weapon weapon) {
        this.weapon = weapon;
    }

    public Armor getArmor() {
        return armor;
    }

    public void setArmor(Armor armor) {
        this.armor = armor;
    }

    public Helm getHelm() {
        return helm;
    }

    public void setHelm(Helm helm) {
        this.helm = helm;
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public int getExperience() {
        return experience;
    }

    public void setExperience(int experience) {
        this.experience = experience;
    }

    public String getHeroClass() {
        return heroClass;
    }

    public void setHeroClass(String heroClass) {
        this.heroClass = heroClass;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Name: ").append(name).append("\n");
        sb.append("Class: ").append(heroClass).append("\n");
        sb.append("Level: ").append(level).append("\n");
        sb.append("XP: ").append(experience).append("\n");
        sb.append("Attack: ").append(attack).append("\n");
        sb.append("Defense: ").append(defense).append("\n");
        sb.append("HP: ").append(hitPoints).append("\n");

        sb.append("Weapon: ");
        if (weapon != null)
            sb.append(weapon.getName()).append(" (attack +").append(weapon.getPoints()).append(")\n");
        else
            sb.append(" no weapon\n");

        sb.append("Helm: ");
        if (helm != null)
            sb.append(helm.getName()).append(" (hp +").append(helm.getPoints()).append(")\n");
        else
            sb.append(" no helmet\n");

        sb.append("Armor: ");
        if (armor != null)
            sb.append(armor.getName()).append(" (defense +").append(armor.getPoints()).append(")\n");
        else
            sb.append(" no armor\n");
        return sb.toString();
    }
}
