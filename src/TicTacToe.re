open TicTacToe__Definitions;
open TicTacToe__Utils;

let initialState = {
  status: Active,
  nextTurn: Cross,
  fields: Array.make(3, Array.make(3, None)),
};

let reducer = (state, action) => {
  switch (action) {
  | Mark(row, column) =>
    let previousField = state->getField(row, column);
    switch (previousField) {
    | None => {
        ...state,
        nextTurn:
          switch (state.nextTurn) {
          | Cross => Circle
          | Circle => Cross
          },
        fields: state->setField(row, column, state.nextTurn),
      }
    | _ => state
    };

  | Finish => {...state, status: state->requestStatus}
  };
};