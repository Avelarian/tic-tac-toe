open Belt;

type fieldState = 
  | Empty
  | Cross
  | Circle;

type action =
  | Mark(int, int)

let fields = Array.make(3, Array.make(3, Empty));

[@react.component]
let make = () => {
  let nextTurn = ref(Cross);
  let gameActive = ref(true);

  let reducer = (state, action) => {
    switch (action) {
    | Mark(row, column) =>
      state->Array.mapWithIndex((rowField, fieldRow) =>
        fieldRow->Array.mapWithIndex((columnField, fieldColumn) => 
          switch (columnField) {
          | fieldIndex =>  {
            nextTurn := nextTurn^ === Cross ? Circle : Cross;
            row === rowField && column === fieldIndex ? nextTurn^ : state->Array.get(row)->Array.get(column);
          };
          | _ => field
          }
        )
      )
    };
  };

  let rowCross = (state) => {

  }

  let (state, dispatch) = React.useReducer(reducer, fields);

  <main>
    {gameActive^ ? "Tic-tac-toe!"->React.string : "Finished!"->React.string}
    <div>
      <button onClick={_ => dispatch(Mark(0, 0))}>
        {state[0] == Empty ? ""->React.string : (state[0] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => dispatch(Mark(0, 1))}>
        {state[1] == Empty ? ""->React.string : (state[1] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => dispatch(Mark(0, 2))}>
        {state[2] == Empty ? ""->React.string : (state[2] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
    </div>
    <div>
      <button onClick={_ => dispatch(Mark(1, 0))}>
        {state[3] == Empty ? ""->React.string : (state[3] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => dispatch(Mark(1, 1))}>
        {state[4] == Empty ? ""->React.string : (state[4] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => dispatch(Mark(1, 2))}>
        {state[5] == Empty ? ""->React.string : (state[5] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
    </div>
    <div>
      <button onClick={_ => dispatch(Mark(2, 0))}>
        {state[6] == Empty ? ""->React.string : (state[6] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => dispatch(Mark(2, 1))}>
        {state[7] == Empty ? ""->React.string : (state[7] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => dispatch(Mark(2. 2))}>
        {state[8] == Empty ? ""->React.string : (state[8] == Cross ? "X"->React.string : "O"->React.string)}
      </button>
    </div>
  </main>;
};
