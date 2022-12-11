#include <iostream>
#include <cmath>

using namespace std;

const float G = 6.67408e-11; //grav constant
const float M = 1.989e30; //mass of celestial body in kg
const float a = 1.496e11; //semi major axis in meters
const float e = 0.017; //eccentricity of celestial body's orbit
const float i = 0.0; //inclination of the celestial body's orbit in degrees
const float w = 90.0; // define the arg of periapsis of the celestial body's orbit in degrees
const float O = 0.0; //the longitude of the ascending node in degrees
const float M0 = 0.0; //mean anomoly in degrees
const float T = 2457000.5; //epoch of orbit in Julian days

//orbital period of the celestial body in seconds
float P = 2 * M_PI * sqrt(pow(a, 3) / (G*M));

/* convert the incl, arg or per, and longitude of the asc node from degrees to rad */
float i_rad = i * M_PI / 180.0;
float w_rad = w * M_PI / 180.0;
float O_rad = O * M_PI / 180.0;

/* convert the mean anomoly from deg to rad and calculate the mean motion in rads per seconds */
float M_rad = M0 * M_PI / 180.0;
float n_rad = 2 * M_PI / P;

/* calc the eccentric anomaly using mean anomaly and ecc */
float E = M_rad + e * sin(M_rad);

/* calculate the true anomaly using the ecc anomaly */
float f = 2 * atan(sqrt((1 + e)/(1-e)) * tan(E/2.0));

/* calculate the rectangular coords in the plane of the orbit */
float x = a * (cos(E) - e);
float y = a * sqrt(1 - pow(e, 2)) * sin(E);

/* rotate the coords by the args of the periapsis to obtain the coords in the plane of the celestial body's orbit */
float x_rot = x * cos(w_rad) - y * sin(w_rad);
float y_rot = x * sin(w_rad) + y * cos(w_rad);

//rotate the coords by the incl and longitude of the ascending node to obtain the coords in the celestial body's referce frame
float x_final = x_rot * cos(O_rad) - y_rot * sin(O_rad) * cos(i_rad);
float y_final = x_rot * sin(O_rad) + y_rot * cos(O_rad) * cos(i_rad);
float z_final = y_rot * sin(i_rad);

/*print the final */
int main(){
	cout << x_final << " " << y_final << " " << z_final << endl;
}
