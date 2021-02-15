/* 4 */
type meza =
  | Shrimp
  | Calamari
  | Escargots
  | Hummus

/* 5 */
type main =
  | Steak
  | Ravioli
  | Chicken
  | Eggplant

type salad =
  | Green
  | Cucumber
  | Greek

/* 6 */
type dessert =
  | Sundae
  | Mousse
  | Torte

/* 25 */
let add_a_steak = x =>
  switch x {
  | Shrimp => (Shrimp, Steak)
  | Calamari => (Calamari, Steak)
  | Escargots => (Escargots, Steak)
  | Hummus => (Hummus, Steak)
  }

/* 42 */
/* No way I'm typing all that */

/* 46 */
let eq_main = x =>
  switch x {
  | (Steak, Steak) => true
  | (Ravioli, Ravioli) => true
  | (Chicken, Chicken) => true
  | (Eggplant, Eggplant) => true
  | (a_main, another_main) => false
  }

/* 54 */
let has_steak = x =>
  switch x {
  | (meza, Steak, dessert) => true
  | (meza, main, dessert) => false
  }

/* 66 */
let has_steak: ((meza, main, dessert)) => bool = x =>
  switch x {
  | (a, Steak, d) => true
  | (a, ns, d) => false
  }

/* 67 */
let add_a_steak: meza => (meza, main) = x => (x, Steak)
/* Shorter: */
let add_a_steak = (x: meza) => (x, Steak)
