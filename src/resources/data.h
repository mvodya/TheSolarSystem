#include "../physics/space/moon.h"
#include "../physics/space/planet.h"

void LOAD_DATA(std::vector<Object *> &objects, Physics *physics) {
  /* TODO: Звезда
   * Солнце
   * https://ru.wikipedia.org/wiki/Солнце
   */
  Planet *sun =
      new Planet("Sun", 8, sf::Color(0xfffcd1ff), sf::Color(0xffb917ff));
  objects.push_back(sun);

  /* Планета
   * Земля
   * https://ru.wikipedia.org/wiki/Земля
   */
  Planet *earth =
      new Planet("Earth", 3, sf::Color(0x4dccf0ff), sf::Color(0x0a6906ff));
  objects.push_back(earth);
  earth->apogee.ae(0.98329134);
  earth->perigee.ae(1.00000261);
  earth->speed.km(107218);
  earth->Init(physics);

  /* Планета
   * Земля
   * https://ru.wikipedia.org/wiki/Луна
   */
  Moon *moon = new Moon("Moon", 1.5, sf::Color(0x999999ff),
                        sf::Color(0x575757ff), earth);
  objects.push_back(moon);
  moon->apogee.km(404000 * 50);
  moon->perigee.km(363104 * 50);
  moon->speed.km(3682 * 200);
  moon->Init(physics);

  /* Планета
   * Марс
   * https://ru.wikipedia.org/wiki/Марс
   */
  Planet *mars =
      new Planet("Mars", 2.5, sf::Color(0xeb6200ff), sf::Color(0x8c4919ff));
  objects.push_back(mars);
  mars->apogee.ae(1.381);
  mars->perigee.ae(1.666);
  mars->speed.km(86400);
  mars->Init(physics);
}
