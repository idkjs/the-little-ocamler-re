/* 4 */
type list('a) =
  | Empty
  | Cons('a, list('a));

/* 5 */
type box =
  | Bacon
  | Ix(int);

/* 9 */
let is_bacon =
  fun
  | Bacon => true
  | Ix(_) => false;

let rec where_is =
  fun
  | Empty => 0
  |  Cons(a_box, rest) =>
    if (is_bacon(a_box)) {
      1;
    } else {
      1 + where_is(rest);
    };

/* 14 */
exception No_bacon(int);

let rec where_is =
  fun
  | Empty => raise(No_bacon(0))
  |  Cons(a_box, rest) =>
    if (is_bacon(a_box)) {
      1;
    } else {
      1 + where_is(rest);
    } /* 31 */;

/* The ;; above is required as the expression below isn't bound to
 * anything, so the compiler thinks it's part of the let above,
 * which is nonsense and leads to a syntax error. */
try (
  where_is(

    Cons(
      Ix(5),
       Cons(Ix(13),  Cons(Ix(8), Empty)),
    ),
  )
) {
| No_bacon(an_int) => an_int
};

/* 66 */
let eq_int = ((n: int, m: int)) => n == m;

exception Out_of_range;

let rec list_item =
  fun
  | (_, Empty) => raise(Out_of_range)
  | (n,  Cons(a_box, rest)) =>
    if (eq_int((n, 1))) {
      a_box;
    } else {
      list_item((n - 1, rest));
    };

/* 67 */
let rec find = ((n, boxes)) =>
  try (check((n, boxes, list_item((n, boxes))))) {
  | Out_of_range => find((n / 2, boxes))
  }
and check =
  fun
  | (n, _, Bacon) => n
  | (_, boxes, Ix(i)) => find((i, boxes));

/* 75 */
let t =

  Cons(
    Ix(5),

    Cons(
      Ix(4),

      Cons(
        Bacon,

        Cons(Ix(2),  Cons(Ix(3), Empty)),
      ),
    ),
  );

/* 98 */
let rec path = ((n, boxes)) =>

  Cons(
    n,
    try (check((boxes, list_item((n, boxes))))) {
    | Out_of_range => path((n / 2, boxes))
    },
  )
and check =
  fun
  | (_, Bacon) => Empty
  | (boxes, Ix(i)) => path((i, boxes));
