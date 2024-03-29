/* 6 */
type fruit =
  | Peach
  | Apple
  | Pear
  | Lemon
  | Fig;

type tree =
  | Bud
  | Flat(fruit, tree)
  | Split(tree, tree);

/* 11 */
let rec flat_only =
  fun
  | Bud => true
  |  Flat(_f, t) => flat_only(t)
  |  Split(_s, _t) => false;

/* 18 */
let rec split_only =
  fun
  | Bud => true
  |  Flat(_f, _t) => false
  |  Split(s, t) => split_only(s) && split_only(t);

/* 22 */
let rec contains_fruit' =
  fun
  | Bud => false
  |  Flat(_f, _t) => true
  |  Split(s, t) => contains_fruit'(s) || contains_fruit'(t);

let contains_fruit = x => split_only(x);

/* 34 */
let less_than = ((n: int, m: int)) => n < m;

let larger_of = ((n, m)) =>
  if (less_than((n, m))) {
    m;
  } else {
    n;
  };

/* 39 */
let eq_fruit =
  fun
  | (Peach, Peach) => true
  | (Apple, Apple) => true
  | (Pear, Pear) => true
  | (Lemon, Lemon) => true
  | (Fig, Fig) => true
  | (_, _) => false;

/* 41 */
let rec subst_in_tree =
  fun
  | (_, _, Bud) => Bud
  | (n, a,  Flat(f, t)) =>
    if (eq_fruit((f, a))) {
       Flat(n, subst_in_tree((n, a, t)));
    } else {
       Flat(f, subst_in_tree((n, a, t)));
    }
  | (n, a,  Split(s, t)) =>

    Split(subst_in_tree((n, a, s)), subst_in_tree((n, a, t)));

/* 43 */
let rec occurs =
  fun
  | (_, Bud) => 0
  | (n,  Flat(f, t)) =>
    if (eq_fruit((n, f))) {
      1 + occurs((n, t));
    } else {
      occurs((n, t));
    }
  | (n,  Split(s, t)) => occurs((n, s)) + occurs((n, t));

/* 51 */
type slist('a) =
  | Empty
  | Scons(sexp('a), slist('a))
and sexp('a) =
  | An_atom('a)
  | A_slist(slist('a));

/* 57 */
let rec occurs_in_slist =
  fun
  | (_, Empty) => 0
  | (a,  Scons(s, y)) =>
    occurs_in_sexp((a, s)) + occurs_in_slist((a, y))
and occurs_in_sexp =
  fun
  | (a, An_atom(b)) =>
    if (eq_fruit((b, a))) {
      1;
    } else {
      0;
    }
  | (a, A_slist(y)) => occurs_in_slist((a, y));

/* 58 */
let rec subst_in_slist =
  fun
  | (_, _, Empty) => Empty
  | (n, a,  Scons(s, y)) =>

    Scons(subst_in_sexp((n, a, s)), subst_in_slist((n, a, y)))
and subst_in_sexp =
  fun
  | (n, a, An_atom(b)) =>
    if (eq_fruit((b, a))) {
      An_atom(n);
    } else {
      An_atom(b);
    }
  | (n, a, A_slist(y)) => A_slist(subst_in_slist((n, a, y)));

/* 65 */
let rec eq_fruit_in_atom =
  fun
  | (a, An_atom(s)) => eq_fruit((a, s))
  | (_, A_slist(_)) => false;

/* 68 */
let rec rem_from_slist =
  fun
  | (_, Empty) => Empty
  | (a,  Scons(s, y)) =>
    if (eq_fruit_in_atom((a, s))) {
      rem_from_slist((a, y));
    } else {

      Scons(rem_from_sexp((a, s)), rem_from_slist((a, y)));
    }
and rem_from_sexp =
  fun
  | (_, An_atom(b)) => An_atom(b)
  | (a, A_slist(y)) => A_slist(rem_from_slist((a, y)));

/* 76 */
let rec rem_from_slist =
  fun
  | (_, Empty) => Empty
  | (a,  Scons(An_atom(b), y)) =>
    if (eq_fruit((a, b))) {
      rem_from_slist((a, y));
    } else {
       Scons(An_atom(b), rem_from_slist((a, y)));
    }
  | (a,  Scons(A_slist(x), y)) =>

    Scons(A_slist(rem_from_slist((a, x))), rem_from_slist((a, y)));
