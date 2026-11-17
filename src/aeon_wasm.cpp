#include <cmath>
#include <cstddef>
#include <cstdint>

// Returns 0 on success; -1 for invalid pointer; -2 for out-of-range inputs.
// out[0..5] = atmosphere mass, crust mass, lithostatic pressure,
// rotational energy, tidal differential acceleration, R06-R04 temperature contrast.
extern "C" int aeon_calculate(const double* in, double* out) {
  if (!in || !out) return -1;
  const double p=in[0], crust=in[1], day=in[2], moon=in[3], magma=in[4], hydro=in[5];
  if (!std::isfinite(p)||!std::isfinite(crust)||!std::isfinite(day)||!std::isfinite(moon)||!std::isfinite(magma)||!std::isfinite(hydro)) return -2;
  if (p<0.5||p>1.5||crust<20||crust>40||day<14||day>17.5||moon<236000||moon>287000||magma<1200||magma>1600||hydro<100||hydro>400) return -2;
  constexpr double pi=3.14159265358979323846, G=6.67430e-11, moon_mass=7.342e22;
  constexpr double radius=6.371e6, earth_mass=5.972e24, inertia_factor=.3307;
  constexpr double atmosphere_base=5.20e18, crust_base=4.60e22, density=3000, gravity=9.81;
  const double omega=2*pi/(day*3600), inertia=inertia_factor*earth_mass*radius*radius;
  const double moon_m=moon*1000;
  out[0]=atmosphere_base*p;
  out[1]=crust_base*crust/30.0;
  out[2]=density*gravity*crust*1000/1e9;
  out[3]=.5*inertia*omega*omega;
  out[4]=2*G*moon_mass*radius/(moon_m*moon_m*moon_m);
  out[5]=magma-hydro;
  return 0;
}
