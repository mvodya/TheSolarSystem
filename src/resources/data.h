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

  /* Планета
   * Юпитер
   * https://ru.wikipedia.org/wiki/Юпитер
   */
  Planet *jupiter =
      new Planet("Jupiter", 7, sf::Color(0x4dccf0ff), sf::Color(0x0a6906ff));
  objects.push_back(jupiter);
  jupiter->apogee.ae(5.458104);
  jupiter->perigee.ae(4.950429);
  jupiter->speed.km(47052);
  jupiter->Init(physics);

  /* Планета
   * Сатурн
   * https://ru.wikipedia.org/wiki/Сатурн
   */
  Planet *saturn =
      new Planet("Saturn", 6, sf::Color(0x4dccf0ff), sf::Color(0x0a6906ff));
  objects.push_back(saturn);
  saturn->apogee.ae(10.116);
  saturn->perigee.ae(9.048);
  saturn->speed.km(34884);
  saturn->Init(physics);

  /* Планета
   * Уран
   * https://ru.wikipedia.org/wiki/Уран_(планета)
   */
  Planet *uranus =
      new Planet("Uranus", 6, sf::Color(0x4dccf0ff), sf::Color(0x0a6906ff));
  objects.push_back(uranus);
  uranus->apogee.ae(20.08330526);
  uranus->perigee.ae(18.37551863);
  uranus->speed.km(24516);
  uranus->Init(physics);

  /* Планета
   * Нептун
   * https://ru.wikipedia.org/wiki/Нептун
   */
  Planet *neptune =
      new Planet("Neptune", 6, sf::Color(0x4dccf0ff), sf::Color(0x0a6906ff));
  objects.push_back(neptune);
  neptune->apogee.ae(30.44125206);
  neptune->perigee.ae(29.76607095);
  neptune->speed.km(19565);
  neptune->Init(physics);

  /* Планета
   * Плутон
   * https://ru.wikipedia.org/wiki/Плутонpluto
   */
  Planet *pluto =
      new Planet("Pluto", 1.8, sf::Color(0x4dccf0ff), sf::Color(0x0a6906ff));
  objects.push_back(pluto);
  pluto->apogee.ae(49.31);
  pluto->perigee.ae(29.667);
  pluto->speed.km(16808);
  pluto->Init(physics);
}
