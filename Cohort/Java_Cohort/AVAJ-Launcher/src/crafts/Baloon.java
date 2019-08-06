package crafts;

import simulator.*;


import java.util.HashMap;

public class Baloon extends Aircraft implements Flyable {

    private WeatherTower weatherTower;

    Baloon(String name, Coordinates coordinates) {
        super(name, coordinates);

    }

    public void updateConditions() {
        HashMap<String, String> map = new HashMap<>();
        map.put("SUN", "It is sunny.");
        map.put("FOG", "There's a fog .");
        map.put("SNOW", "It is cold.");
        map.put("RAIN", "Its rainy.");


        String weather = weatherTower.getWeather(this.coordinates);

        if (weather.equals("SUN")) {
            this.coordinates = new Coordinates(coordinates.getLongitude() + 2, coordinates.getLatitude(),
                    coordinates.getHeight() + 4 > 100 ? 100 : coordinates.getHeight() + 4);
        }
        if (weather.equals("RAIN")) {
            this.coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(),
                    coordinates.getHeight() - 5 < 0 ? 0 : coordinates.getHeight() - 5);
        }
        if (weather.equals("FOG")) {
            this.coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(),
                    coordinates.getHeight() - 3 < 0 ? 0 : coordinates.getHeight() - 3);
        }
        if (weather.equals("SNOW")) {
            this.coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(),
                    coordinates.getHeight() - 15 < 0 ? 0 : coordinates.getHeight() - 15);
        }
        if (coordinates.getHeight() == 0) {
            Logger.addMessage("Baloon# " + this.name + this.id + " landing.");
            this.weatherTower.unregister(this);
        }

        Logger.addMessage("Baloon#" + this.name + "(" + this.id + "): " + map.get(weather));
    }

    public void registerTower(WeatherTower weatherTower) {
        this.weatherTower = weatherTower;
        this.weatherTower.register(this);
        Logger.addMessage("Tower says: Baloon#" + this.name + "(" + this.id + ") registered to weather tower.");
    }
}
