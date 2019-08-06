package simulator;

import java.io.BufferedReader;
//import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import crafts.*;

import java.util.ArrayList;

public class Simulator {

    private static WeatherTower weatherTower;
    private static ArrayList<Flyable> flyables = new ArrayList<>();

    public static void main(String[] args) {


        try (BufferedReader reader = new BufferedReader(new FileReader(args[0]))) {
            String line = reader.readLine();
            if (line != null) {
                weatherTower = new WeatherTower();
                int simulations = Integer.parseInt(line.split(" ")[0]);

                if (simulations <= 0) {
                    System.out.println("Invalid simulations " + simulations);
                    System.exit(1);
                }
                while ((line = reader.readLine()) != null) {
                    Flyable flyable = AircraftFactory.newAircraft(line.split(" ")[0], line.split(" ")[1],
                            Integer.parseInt(line.split(" ")[2]), Integer.parseInt(line.split(" ")[3]),
                            Integer.parseInt(line.split(" ")[4]));
                    flyables.add(flyable);
                }

                for (Flyable flyable : flyables) {
                    flyable.registerTower(weatherTower);
                }
                for (int i = 1; i <= simulations; i++) {
                    weatherTower.changeWeather();
                }
            }
        } catch (IOException e) {
            System.exit(1);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.exit(1);
        } catch (NumberFormatException e) {
            System.exit(1);
        } finally {
            Logger.logMessage();
        }
    }
}
