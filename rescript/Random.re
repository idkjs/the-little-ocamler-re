let rec fact = n =>
  if (n < 2) {
    1;
  } else {
    n * fact(n - 1);
  };

let succ = x => x + 1;

let compose = (f, g, x) => f(g(x));

let _ = compose(fact, succ, 8);

let compose = (f, g, x) => f(g(x));
