/* 4 */
type rec list<'a> =
  | Empty
  | Cons('a, list<'a>)

/* 5 */
type box =
  | Bacon
  | Ix(int)

/* 9 */
let is_bacon = x =>
  switch x {
  | Bacon => true
  | Ix(_n) => false
  }

let rec where_is' = x =>
  switch x {
  | Empty => 0
  | @implicit_arity Cons(a_box, rest) =>
    if is_bacon(a_box) {
      1
    } else {
      1 + where_is'(rest)
    }
  }

/* 14 */
exception No_bacon(int)

let rec where_is = x =>
  switch x {
  | Empty => raise(No_bacon(0))
  | @implicit_arity Cons(a_box, rest) =>
    if is_bacon(a_box) {
      1
    } else {
      1 + where_is(rest)
    }
  } /* 31 */

/* The ;; above is required as the expression below isn't bound to
 * anything, so the compiler thinks it's part of the let above,
 * which is nonsense and leads to a syntax error. */
let _ = try where_is(
  @implicit_arity Cons(Ix(5), @implicit_arity Cons(Ix(13), @implicit_arity Cons(Ix(8), Empty))),
) catch {
| No_bacon(an_int) => an_int
}

/* 66 */
let eq_int = ((n: int, m: int)) => n == m

exception Out_of_range

let rec list_item = x =>
  switch x {
  | (n, Empty) => raise(Out_of_range)
  | (n, @implicit_arity Cons(a_box, rest)) =>
    if eq_int((n, 1)) {
      a_box
    } else {
      list_item((n - 1, rest))
    }
  }

/* 67 */
let rec find = ((n, boxes)) =>
  try check((n, boxes, list_item((n, boxes)))) catch {
  | Out_of_range => find((n / 2, boxes))
  }
and check = x =>
  switch x {
  | (n, _boxes, Bacon) => n
  | (_n, boxes, Ix(i)) => find((i, boxes))
  }

/* 75 */
let t =
  @implicit_arity
  Cons(
    Ix(5),
    @implicit_arity
    Cons(
      Ix(4),
      @implicit_arity Cons(Bacon, @implicit_arity Cons(Ix(2), @implicit_arity Cons(Ix(3), Empty))),
    ),
  )

/* 98 */
let rec path = ((n, boxes)) => @implicit_arity
Cons(
  n,
  try check((boxes, list_item((n, boxes)))) catch {
  | Out_of_range => path((n / 2, boxes))
  },
)
and check = x =>
  switch x {
  | (_boxes, Bacon) => Empty
  | (boxes, Ix(i)) => path((i, boxes))
  }
