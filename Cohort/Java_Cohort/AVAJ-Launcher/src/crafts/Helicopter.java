package crafts;

import simulator.*;

import java.util.HashMap;

public class Helicopter extends Aircraft implements Flyable {

    private WeatherTower weatherTower;

    Helicopter(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public void updateConditions() {
        HashMap<String, String> map = new HashMap<>();
        map.put("SUN", "I am burning!");
        map.put("FOG", "I cannot see because of the mist .");
        map.put("SNOW", "I am freezing out here.");
        map.put("RAIN", "i am getting wet here!");


        String weather = weatherTower.getWeather(this.coordinates);

        if (weather.equals("SUN")) {
            this.coordinates = new Coordinates(coordinates.getLongitude() + 10, coordinates.getLatitude(),
                    coordinates.getHeight() + 2 > 100 ? 100 : coordinates.getHeight() + 2);
        }
        if (weather.equals("RAIN")) {
            this.coordinates = new Coordinates(coordinates.getLongitude() + 5, coordinates.getLatitude(),
                    coordinates.getHeight());
        }
        if (weather.equals("FOG")) {
            this.coordinates = new Coordinates(coordinates.getLongitude() + 1, coordinates.getLatitude(),
                    coordinates.getHeight());
        }
        if (weather.equals("SNOW")) {
            this.coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(),
                    coordinates.getHeight() - 12 < 0 ? 0 : coordinates.getHeight() - 12);
        }
        if (coordinates.getHeight() == 0) {
            Logger.addMessage("Helicopter# " + this.name + this.id + " landing.");
            this.weatherTower.unregister(this);
        }

        Logger.addMessage("Helicopter#" + this.name + "(" + this.id + "): " + map.get(weather));
    }

    public void registerTower(WeatherTower weatherTower) {
        this.weatherTower = weatherTower;
        this.weatherTower.register(this);
        Logger.addMessage("Tower says: Helicopter#" + this.name + "(" + this.id + ") registered to weather tower.");
    }

    public void unregisterTower() {
        this.weatherTower.unregister(this);
    }
}
