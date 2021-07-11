/* 1 */
type pizza('a) =
  | Bottom
  | Topping(('a, pizza('a)));

/* 3 */
type fish =
  | Anchovy
  | Lox
  | Tuna;

/* 11 */
let rec rem_anchovy' =
  fun
  | Bottom => Bottom
  | Topping((Anchovy, p)) => rem_anchovy'(p)
  | Topping((Tuna, p)) => Topping((Tuna, rem_anchovy'(p)))
  | Topping((Lox, p)) => Topping((Lox, rem_anchovy'(p)));

/* 13 */
let rec rem_anchovy2 =
  fun
  | Bottom => Bottom
  | Topping((Anchovy, p)) => rem_anchovy2(p)
  | Topping((t, p)) => Topping((t, rem_anchovy2(p)));

/* 14 */
let rec rem_tuna =
  fun
  | Bottom => Bottom
  | Topping((Anchovy, p)) => Topping((Anchovy, rem_tuna(p)))
  | Topping((Tuna, p)) => rem_tuna(p)
  | Topping((Lox, p)) => Topping((Lox, rem_tuna(p)));

/* 17 */
// type fish =
//   | Tuna
//   | Lox
//   | Anchovy;

/* 21 */
let rec rem_tuna =
  fun
  | Bottom => Bottom
  | Topping((Tuna, p)) => rem_tuna(p)
  | Topping((t, p)) => Topping((t, rem_tuna(p)));

/* 38 */
let rec eq_fish =
  fun
  | (Anchovy, Anchovy) => true
  | (Lox, Lox) => true
  | (Tuna, Tuna) => true
  | (_a_fish, _another_fish) => false;

/* 40 */
let rec rem_fish =
  fun
  | (_x, Bottom) => Bottom
  | (x, Topping((t, p))) =>
    if (eq_fish((t, x))) {
      rem_fish((x, p));
    } else {
      Topping((t, rem_fish((x, p))));
    };

/* 57 */
let eq_int = ((n: int, m: int)) => n == m;
/* This also works*/
let eq_int: ((int, int)) => bool = (
  ((n, m)) => n == m: ((int, int)) => bool
);

let rec rem_int =
  fun
  | (_x, Bottom) => Bottom
  | (x, Topping((t, p))) =>
    if (eq_int((t, x))) {
      rem_int((x, p));
    } else {
      Topping((t, rem_int((x, p))));
    };

/* 66 */
let rec subst_fish =
  fun
  | (_n, _a, Bottom) => Bottom
  | (n, a, Topping((t, p))) =>
    if (eq_fish((t, a))) {
      Topping((n, subst_fish((n, a, p))));
    } else {
      Topping((t, subst_fish((n, a, p))));
    };

let rec subst_int =
  fun
  | (_n, _a, Bottom) => Bottom
  | (n, a, Topping((t, p))) =>
    if (eq_int((t, a))) {
      Topping((n, subst_int((n, a, p))));
    } else {
      Topping((t, subst_int((n, a, p))));
    };


/* 71 */
open Chapter01;
let rec eq_num =
  fun
  | (Zero, Zero) => true
  | (One_more_than(n), One_more_than(m)) => eq_num((n, m))
  | (_n, _m) => false;
