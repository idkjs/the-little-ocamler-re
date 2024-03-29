/* 1 */
type list('a) =
  | Empty
  | Cons('a, list('a));

let eq_int = ((n: int, m: int)) => n == m;

let l =

  Cons(
    15,

    Cons(
      6,

      Cons(
        15,

        Cons(
          17,
           Cons(15,  Cons(8, Empty)),
        ),
      ),
    ),
  );

/* 3 */
type orapl =
  | Orange
  | Apple;

let eq_orapl =
  fun
  | (Orange, Orange) => true
  | (Apple, Apple) => true
  | (_, _) => false;

/* 4 */
let rec subst_int =
  fun
  | (_, _, Empty) => Empty
  | (n, a,  Cons(e, t)) =>
    if (eq_int((a, e))) {
       Cons(n, subst_int((n, a, t)));
    } else {
       Cons(e, subst_int((n, a, t)));
    };

let rec subst_orapl =
  fun
  | (_, _, Empty) => Empty
  | (n, a,  Cons(e, t)) =>
    if (eq_orapl((a, e))) {
       Cons(n, subst_orapl((n, a, t)));
    } else {
       Cons(e, subst_orapl((n, a, t)));
    };

/* 9 */
let rec subst =
  fun
  | (_, _, _, Empty) => Empty
  | (rel, n, a,  Cons(e, t)) =>
    if (rel((a, e))) {
       Cons(n, subst((rel, n, a, t)));
    } else {
       Cons(e, subst((rel, n, a, t)));
    };

/* 33 */
let less_than = ((n: int, m: int)) => n < m;

let in_range = (((small, large), x)) =>
  less_than((small, x)) && less_than((x, large));

/* 40 */
let rec subst_pred =
  fun
  | (_, _, Empty) => Empty
  | (pred, n,  Cons(e, t)) =>
    if (pred(e)) {
       Cons(n, subst_pred((pred, n, t)));
    } else {
       Cons(e, subst_pred((pred, n, t)));
    };

/* 48 */
let is_15 = x => eq_int((x, 15));

/* 52 */
let less_than_15 = x => less_than((x, 15));

/* 59 */
let in_range_11_16 = x => less_than((11, x)) && less_than((x, 16));

/* 65 */
let in_range_c = ((small, large), x) =>
  less_than((small, x)) && less_than((x, large));

/* 79 */
let rec subst_c = pred =>
  fun
  | (_, Empty) => Empty
  | (n,  Cons(e, t)) =>
    if (pred(e)) {
       Cons(n, subst_c(pred, (n, t)));
    } else {
       Cons(e, subst_c(pred, (n, t)));
    };

/* 88 */
let rec combine =
  fun
  | (Empty, Empty) => Empty
  | (Empty,  Cons(b, l2)) =>  Cons(b, l2)
  | ( Cons(a, l1), Empty) =>  Cons(a, l1)
  | ( Cons(a, l1),  Cons(b, l2)) =>
     Cons(a, combine((l1,  Cons(b, l2))));

let rec combine =
  fun
  | (Empty, l2) => l2
  | ( Cons(a, l1), l2) =>
     Cons(a, combine((l1, l2)));

/* 93 */
let rec combine_c =
  fun
  | Empty => (l2 => l2)
  |  Cons(a, l1) => (
      l2 =>  Cons(a, combine_c(l1, l2))
    );

/* 95 */
let prefixer_123 = l2 =>

  Cons(1,  Cons(2,  Cons(3, l2)));

/* 97 */
let waiting_prefix_123 = l2 =>

  Cons(
    1,
    combine_c(
       Cons(2,  Cons(3, Empty)),
      l2,
    ),
  );

/* 104 */
let base = l2 => l2;

/* 115 */
let rec combine_s =
  fun
  | Empty => base
  |  Cons(a, l1) => make_cons((a, combine_s(l1)))
and make_cons = ((a, f), l2) =>  Cons(a, f(l2));
