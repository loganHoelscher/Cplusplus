#include <fstream>
#include <cstdlib> 
#include <cstdio> 
#include <cmath> 
#include <fstream> 
#include <vector> 
#include <iostream> 
#include <cassert> 

struct vec3 {
  double x,y,z;
  vec3(double x, double y, double z) : x(x), y(y), z(z) {}
  vec3 operator + (const vec3& v) const { return vec3(x+v.x, y+v.y, z+v.z); }
  vec3 operator - (const vec3& v) const { return vec3(x-v.x, y-v.y, z-v.z); }
  vec3 operator * (double d) const { return vec3(x*d, y*d, z*d); }
  vec3 operator / (double d) const { return vec3(x/d, y/d, z/d); }
  
  vec3 normalize() const {
    double mg = sqrt(x*x + y*y + z*z);
    return vec3(x/mg,y/mg,z/mg);
  }
  };


inline double dot(const vec3& a, const vec3& b) 
{
  return (a.x*b.x + a.y*b.y + a.z*b.z);
}


struct Ray {
  vec3 origin, direction;
  Ray(const vec3& origin, const vec3& direction) : origin(origin), direction(direction) {}
};

struct Sphere {
  vec3 center;
  double radius;
  
  Sphere(const vec3& center, double radius) : center(center), radius(radius) {}
		 
  vec3 getNormal(const vec3& pi) const { return (pi - center) / radius; }
  
  bool intersect(const Ray& ray, double &t) const {
      const vec3 origin = ray.origin;
      const vec3 direction = ray.direction;
      const vec3 oc = origin - center;
      const double b = 2 * dot(oc, direction);
      const double c = dot(oc, oc) - radius*radius;
      double disc = b*b - 4 * c;
      if (disc < 1e-4) return false;
      disc = sqrt(disc);
      const double t0 = -b - disc;
      const double t1 = -b + disc;
      t = (t0 < t1) ? t0 : t1;
      return true;
    }
  };
  
void confine(vec3& col) {
  col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
  col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
  col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
}

int main() {

	
  const int Height = 500;
  const int Width = 500;

  const vec3 white(255, 255, 255);
  const vec3 black(0, 0, 0);
  const vec3 red(255, 0, 0);
  const vec3 green(0, 255, 0);
  const vec3 blue(0, 0, 255);
  const vec3 yellow(255, 255, 0);

  const Sphere sphere(vec3(Width * 0.5, Height * 0.5, 50), 50);
  const Sphere light(vec3(0, 0, 50), 1);
  
  const Sphere sphere1(vec3(Width * 0.65, Height * 0.65, 70), 70);
  const Sphere sphere2(vec3(Width * 0.8, Height * 0.8, 90), 90);
  const Sphere groundSphere(vec3(Width * 0.5, 600, -100),300);
  
  //const Plane plane(vec3(Width, Height * 0.5, 50), 50);

  std::ofstream out("out.ppm");
  out << "P3\n" << Width << ' ' << Height << ' ' << "255\n";

  double t;
  vec3 pixelColor(white);
  int x, y;
  int pixels[x][y];

  for (y = 0; y < Height; ++y) {
    for (x = 0; x < Width; ++x) {
      pixelColor = white;

      const Ray ray(vec3(x,y,0), vec3(0,0,1));
	  
	  
      if (groundSphere.intersect(ray, t)) {
        const vec3 pointOfIntersect = ray.origin + ray.direction *t;
        const vec3 L = light.center - pointOfIntersect;
        const vec3 N = groundSphere.getNormal(pointOfIntersect);
        const double dt = dot(L.normalize(), N.normalize());
		
        pixelColor = (yellow + white*dt) * 0.5;
        confine(pixelColor);
		
		const Ray shadowRay(pointOfIntersect, light.center);
		if(sphere.intersect(shadowRay, t))
		{
			pixelColor =(yellow);
			confine(pixelColor);
		}
		else
		{
	        pixelColor = (yellow + white*dt) * 0.5;
	        confine(pixelColor);
			
		}

      }
	  
      if (sphere.intersect(ray, t)) {
        const vec3 pointOfIntersect = ray.origin + ray.direction *t;
        const vec3 L = light.center - pointOfIntersect;
        const vec3 N = sphere.getNormal(pointOfIntersect);
        const double dt = dot(L.normalize(), N.normalize());

        pixelColor = (blue + white*dt) * 0.5;
        confine(pixelColor);
      }
	  
      if (sphere1.intersect(ray, t)) {
        const vec3 pointOfIntersect = ray.origin + ray.direction *t;
        const vec3 L = light.center - pointOfIntersect;
        const vec3 N = sphere1.getNormal(pointOfIntersect);
        const double dt = dot(L.normalize(), N.normalize());

        pixelColor = (green + white*dt) * 0.5;
        confine(pixelColor);
      }
	  
      if (sphere2.intersect(ray, t)) {
        const vec3 pointOfIntersect = ray.origin + ray.direction *t;
        const vec3 L = light.center - pointOfIntersect;
        const vec3 N = sphere2.getNormal(pointOfIntersect);
        const double dt = dot(L.normalize(), N.normalize());

        pixelColor = (red + white*dt) * 0.5;
        confine(pixelColor);
      }
	  
      out << (int)pixelColor.x << ' '
          << (int)pixelColor.y << ' '
          << (int)pixelColor.z << '\n';
    }
  }
}