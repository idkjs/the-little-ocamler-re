/* 1 */
type rec shish_kebab =
  | Skewer
  | Onion(shish_kebab)
  | Lamb(shish_kebab)
  | Tomato(shish_kebab)

/* 15 */
let rec only_onions = x =>
  switch x {
  | Skewer => true
  | Onion(x) => only_onions(x)
  | Lamb(_x) => false
  | Tomato(_x) => false
  }

/* 63 */
let rec is_vegetarian = x =>
  switch x {
  | Skewer => true
  | Onion(x) => is_vegetarian(x)
  | Lamb(_x) => false
  | Tomato(x) => is_vegetarian(x)
  }

/* 64 */
type rec shish<'a> =
  | Bottom('a)
  | Onion(shish<'a>)
  | Lamb(shish<'a>)
  | Tomato(shish<'a>)

/* 67 */
type rod =
  | Dagger
  | Fork
  | Sword

/* 68 */
type plate =
  | Gold_plate
  | Silver_plate
  | Brass_plate

/* 73 */
let rec is_veggie = x =>
  switch x {
  | Bottom(_x) => true
  | Onion(x) => is_veggie(x)
  | Lamb(_x) => false
  | Tomato(x) => is_veggie(x)
  }

/* 108 */
let rec what_bottom' = x =>
  switch x {
  | Bottom(x) => x
  | Onion(x) => what_bottom'(x)
  | Lamb(x) => what_bottom'(x)
  | Tomato(x) => what_bottom'(x)
  }
/* Shorter version: */
let rec what_bottom = x =>
  switch x {
  | Bottom(x) => x
  | Onion(x)
  | Lamb(x)
  | Tomato(x) =>
    what_bottom(x)
  }
