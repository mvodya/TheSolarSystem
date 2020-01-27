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
   * Меркурий
   * https://ru.wikipedia.org/wiki/Меркурий
   */
  Planet *mercury =
      new Planet("Mercury", 2, sf::Color(0xffffff), sf::Color(0xffffff));
  objects.push_back(mercury);
  mercury->apogee.ae(0.46670079);
  mercury->perigee.ae(0.30749951);
  mercury->speed.km(170496);
  mercury->Init(physics);

  /* Планета
   * Венера
   * https://ru.wikipedia.org/wiki/Венера
   */
  Planet *venus =
      new Planet("Venus", 3, sf::Color(0xffffff), sf::Color(0xffffff));
  objects.push_back(venus);
  venus->apogee.ae(0.72823128);
  venus->perigee.ae(0.71843270);
  venus->speed.km(126072);
  venus->Init(physics);

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
   * Спутник - Луна
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

  /* Планета
   * Марс
   * Спутник - Фобос
   * https://ru.wikipedia.org/wiki/Фобос
   * http://svagor.com/fobos-cel-poleta-na-mars
   */
  Moon *phobos =
      new Moon("Phobos", 1, sf::Color(0x999999ff), sf::Color(0x575757ff), mars);
  objects.push_back(phobos);
  phobos->apogee.km(9518 * 1000);
  phobos->perigee.km(9235 * 1000);
  phobos->speed.km(7696 * 200);
  phobos->Init(physics);

  /* Планета
   * Марс
   * Спутник - Деймос
   * https://ru.wikipedia.org/wiki/Деймос
   * http://readings.gmik.ru/lecture/2013-KOSMICHESKIY-LIFT-FOBOS-MARS
   */
  Moon *deimos =
      new Moon("Deimos", 1, sf::Color(0x999999ff), sf::Color(0x575757ff), mars);
  objects.push_back(deimos);
  deimos->apogee.km(23500 * 700);
  deimos->perigee.km(23500 * 700);
  deimos->speed.km(3600 * 200);
  deimos->Init(physics);
}
