package crafts;

public class Coordinates {

    private int longitude;
    private int latitude;
    private int height;

    Coordinates(int longitude, int latitude, int height) {

        if (height < 0) {
            height = 0;
        } else if (height > 100) {
            height = 100;
        }
        this.height = height;

        if (longitude < 0) {
            longitude = 0;
        }
        this.longitude = longitude;

        if (latitude < 0) {
            latitude = 0;
        }
        this.latitude = latitude;
    }

    public int getLongitude() {
        return this.longitude;
    }

    public int getLatitude() {
        return this.latitude;
    }

    public int getHeight() {
        return this.height;
    }
}
