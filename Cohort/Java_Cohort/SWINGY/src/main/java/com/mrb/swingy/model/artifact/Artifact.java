package com.mrb.swingy.model.artifact;

/**

 */
public abstract class Artifact {

    private int points;
    protected String name;

    public Artifact(String name, int points) {
        this.name = name;
        this.points = points;
    }

    public int getPoints() {
        return points;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name + " (+" + points + ")";
    }
}
