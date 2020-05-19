open Belt;

type fieldState =
  | Empty
  | Cross
  | Circle;

type action =
  | Mark(int, int, fieldState)
  | FinishGame;

type game = {
  gameActive: bool,
  nextTurn: fieldState,
  fields: array(array(fieldState)),
};

let game = {
  gameActive: true,
  nextTurn: Cross,
  fields: Array.make(3, Array.make(3, Empty)),
};

let switchArray = (array, index) => {
  switch (array->Array.get(index)) {
  | Some(element) => element
  | None => [|Empty, Empty, Empty|]
  };
};

let reducer = (state, action) => {
  switch (action) {
  | Mark(row, column, element) => {
      ...state,
      nextTurn:
        element === Empty
          ? state.nextTurn === Cross ? Circle : Cross : state.nextTurn,
      fields:
        element === Empty
          ? state.fields
            ->Array.mapWithIndex((rowIndex, rowField) => {
                rowField->Array.mapWithIndex((columnIndex, columnField) => {
                  columnIndex === column && rowIndex === row
                    ? state.nextTurn : columnField
                })
              })
          : state.fields,
    }
  | FinishGame =>
    // [0][0], [0][1], [0][2] // Array.get(i) (i+ 1) (i+2)
    // [1][0], [1][1], [1][2]
    // [2][0], [2][1], [2][2]
    // [0][0], [1][0], [2][0]
    // [0][1], [1][1], [2][1]
    // [0][2], [1][2], [2][2]
    // [0][0], [1][1], [2][2]
    {
      // Trying to improve this...
      ...state,
      gameActive:
        state.fields
        ->Array.getBy(rowContent => {
            rowContent == Array.make(3, Cross)
            || rowContent == Array.make(3, Circle)
          })
        != None
          ? false
          : state.fields->switchArray(0)->Array.get(0)
            == state.fields->switchArray(1)->Array.get(0)
            && state.fields->switchArray(0)->Array.get(0)
            == state.fields->switchArray(2)->Array.get(0)
            && (
              state.fields->switchArray(0)->Array.get(0) == Some(Cross)
              || state.fields->switchArray(0)->Array.get(0) == Some(Circle)
            )
              ? false
              : state.fields->switchArray(0)->Array.get(1)
                == state.fields->switchArray(1)->Array.get(1)
                && state.fields->switchArray(0)->Array.get(1)
                == state.fields->switchArray(2)->Array.get(1)
                && (
                  state.fields->switchArray(0)->Array.get(1) == Some(Cross)
                  || state.fields->switchArray(0)->Array.get(1)
                  == Some(Circle)
                )
                  ? false
                  : state.fields->switchArray(0)->Array.get(2)
                    == state.fields->switchArray(1)->Array.get(2)
                    && state.fields->switchArray(0)->Array.get(2)
                    == state.fields->switchArray(2)->Array.get(2)
                    && (
                      state.fields->switchArray(0)->Array.get(2)
                      == Some(Cross)
                      || state.fields->switchArray(0)->Array.get(2)
                      == Some(Circle)
                    )
                      ? false
                      : state.fields->switchArray(0)->Array.get(0)
                        == state.fields->switchArray(1)->Array.get(1)
                        && state.fields->switchArray(0)->Array.get(0)
                        == state.fields->switchArray(2)->Array.get(2)
                        && (
                          state.fields->switchArray(0)->Array.get(0)
                          == Some(Cross)
                          || state.fields->switchArray(0)->Array.get(0)
                          == Some(Circle)
                        )
                          ? false
                          : state.fields->switchArray(0)->Array.get(2)
                            == state.fields->switchArray(1)->Array.get(1)
                            && state.fields->switchArray(2)->Array.get(0)
                            == state.fields->switchArray(1)->Array.get(1)
                            && (
                              state.fields->switchArray(0)->Array.get(2)
                              == Some(Cross)
                              || state.fields->switchArray(0)->Array.get(2)
                              == Some(Circle)
                            )
                              ? false : true,
    }
  };
};