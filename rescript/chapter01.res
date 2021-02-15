/* 16 */
type seasoning =
  | Salt
  | Pepper

/* 21 */
type rec num =
  | Zero
  | One_more_than(num)

/* 32 */
type rec open_faced_sandwich<'a> =
  | Bread('a)
  | Slice(open_faced_sandwich<'a>)
