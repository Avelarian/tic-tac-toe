type field =
  | Cross
  | Circle;

type status =
  | Active
  | Finished;

type action =
  | Mark(int, int)
  | Finish;

type state = {
  status,
  nextTurn: field,
  fields: array(array(option(field))),
};