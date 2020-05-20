open TicTacToe__Definitions;

let getField = (state, row, column) => {
  switch (state.fields->Array.get(row)) {
  | Some(row) =>
    switch (row->Array.get(column)) {
    | Some(field) => field
    | None => None
    }
  | None => None
  };
};

let setField = (state, row, column, field) => {
  state.fields
  ->Array.mapWithIndex((rowIndex, rowField) => {
      rowField->Array.mapWithIndex((columnIndex, columnField) => {
        switch (row === rowIndex, column === columnIndex) {
        | (true, true) => Some(field)
        | _ => columnField
        }
      })
    });
};

let requestStatus = state => {
  let status = ref(Active);
  for (i in 0 to 2) {
    switch (
      getField(state, 0, i) == getField(state, 1, i),
      getField(state, 0, i) == getField(state, 2, i),
      getField(state, 0, i) != None,
    ) {
    | (true, true, true) => status := Finished
    | _ => status := status^
    };
    switch (
      getField(state, i, 0) == getField(state, i, 1),
      getField(state, i, 0) == getField(state, i, 2),
      getField(state, i, 0) != None,
    ) {
    | (true, true, true) =>
      status := Finished;
    | _ => status := status^
    };
  };
  switch (
    getField(state, 0, 0) == getField(state, 1, 1),
    getField(state, 0, 0) == getField(state, 2, 2),
    getField(state, 1, 1) != None,
  ) {
  | (true, true, true) =>
    status := Finished;
  | _ => status := status^
  };
  switch (
    getField(state, 0, 2) == getField(state, 1, 1),
    getField(state, 0, 2) == getField(state, 2, 0),
    getField(state, 1, 1) != None,
  ) {
  | (true, true, true) =>
    status := Finished;
  | _ => status := status^
  };
  status^;
};