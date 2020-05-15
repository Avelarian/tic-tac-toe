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
      state->Array.mapWithIndex((rowIndex, rowField) =>
        rowField->Array.mapWithIndex((columnIndex, columnField) => 
          switch (columnIndex) {
          | columnIndex =>  {
            Js.log(state);
            nextTurn := nextTurn^ === Cross ? Circle : Cross;
            row === rowIndex && column === columnIndex ? nextTurn^ : columnField
          };
          | _ => columnField;
          }
        )
      )
    };
  };

  let switchArray = (array, index) => {
    switch(array->Array.get(index)) {
      | Some(element) => element
      | None => [|Empty, Empty, Empty|];
    }
  }

  let (state, dispatch) = React.useReducer(reducer, fields);

  // let finishGame = () => {
  //   let crossArray = Array.make(3, Cross);
  //   let circleArray = Array.make(3, Circle);
  //   let columnCross = Array.make(3, Empty);
  //   let columnCircle = Array.make(3, Empty);
  //   let stateCross = Array.make(3, Array.make(3, Cross));
  //   let stateCircle = Array.make(3, Array.make(3, Circle));
  //   state->Array.mapWithIndex((row, rowContent) => {
  //     switch rowContent {
  //     | crossArray => gameActive := false;
  //     | circleArray => gameActive := false;
  //     | _ => rowContent->Array.mapWithIndex((column, columnContent) => {
        
  //     })
  //     };
  //   })
  // }

  // React.useEffect1(() => {
  //   let crossArray = Array.make(3, Cross);
  //   let circleArray = Array.make(3, Circle);
  //   let array = state->switchArray(0);
  //   switch (array) {
  //   | crossArray => {
  //     gameActive := false;
  //     crossArray;
  //   }
  //   | 
  //   };
  // }, state);

  <main>
    {gameActive^ ? "Tic-tac-toe!"->React.string : "Finished!"->React.string}
    <div> // state->Array.mapWithIndex((rowIndex, row) => element->switchArray(index)->Array.mapWithIndex(columnIndex, element) =>)
      (
        state->switchArray(0)->Array.mapWithIndex((index, element) => 
          <button onClick={_ => dispatch(Mark(0, index))}>
            {element == Empty ? ""->React.string : (element == Cross ? "X"->React.string : "O"->React.string)}
          </button>
        )
      )->React.array
    </div>
    <div>
      (
        state->switchArray(1)->Array.mapWithIndex((index, element) => 
          <button onClick={_ => dispatch(Mark(1, index))}>
            {element == Empty ? ""->React.string : (element == Cross ? "X"->React.string : "O"->React.string)}
          </button>
        )
      )->React.array
    </div>
    <div>
      (
        state->switchArray(2)->Array.mapWithIndex((index, element) => 
          <button onClick={_ => dispatch(Mark(2, index))}>
            {element == Empty ? ""->React.string : (element == Cross ? "X"->React.string : "O"->React.string)}
          </button>
        )
      )->React.array
    </div>
  </main>;
};
