package simulator;

import crafts.*;

import java.util.Random;

public class WeatherProvider {
    private static WeatherProvider weatherProvider = new WeatherProvider();
    private static String[] weather = {
            "RAIN", "FOG", "SUN", "SNOW"
    };

    public static WeatherProvider getProvider() {

        return WeatherProvider.weatherProvider;
    }

    public String getCurrentWeather(Coordinates coordinates) {
        int rand = 0;
        if (coordinates.getHeight() > 0 && coordinates.getLongitude() > 0 && coordinates.getLatitude() > 0) {
            int coordinateSum = coordinates.getHeight() + coordinates.getLongitude() + coordinates.getLatitude();
            rand = coordinateSum % 4;
            Random random = new Random();
            rand = random.nextInt(3);
        }
        return weather[rand];
    }
}
