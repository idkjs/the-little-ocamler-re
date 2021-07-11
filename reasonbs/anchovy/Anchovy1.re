open Anchovy;

let rec rem_anchovy' =
  fun
  | Bottom => Bottom
  | Topping((Anchovy, p)) => rem_anchovy'(p)
  | Topping((Tuna, p)) => Topping((Tuna, rem_anchovy'(p)))
  | Topping((Lox, p)) => Topping((Lox, rem_anchovy'(p)));

