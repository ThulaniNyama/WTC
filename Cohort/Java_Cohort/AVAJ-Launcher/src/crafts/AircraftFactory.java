package crafts;


public abstract class AircraftFactory {


    public static Flyable newAircraft(String type, String name, int longitude, int latitude, int height) {

        Coordinates coordinates = new Coordinates(longitude, latitude, height);

        Flyable flyable;

        switch (type.toLowerCase()) {
            case "baloon":
                flyable = new Baloon(name, coordinates);
                return flyable;
            case "jetplane":
                flyable = new JetPlane(name, coordinates);
                return flyable;
            case "helicopter":
                flyable = new Helicopter(name, coordinates);
                return flyable;
            default:
                System.out.println("Incorrect aircraft!");
                System.exit(1);
        }
        return null;
    }
}
