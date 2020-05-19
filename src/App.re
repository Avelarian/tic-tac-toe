open Belt;

open TicTacToe;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, game);

  React.useEffect1(
    () => {
      dispatch(FinishGame);
      None;
    },
    state.fields,
  );
  // Trying to improve the structure of the component also...

  <main>
    (state.gameActive ? "Tic-tac-toe!" : "Finished!")->React.string
    <div>
      {state.fields
       ->switchArray(0)
       ->Array.mapWithIndex((index, element) =>
           <button onClick={_ => dispatch(Mark(0, index, element))}>
             {element == Empty
                ? ""->React.string
                : element == Cross ? "X"->React.string : "O"->React.string}
           </button>
         )
       ->React.array}
    </div> // state->Array.mapWithIndex((rowIndex, row) => element->switchArray(index)->Array.mapWithIndex(columnIndex, element) =>)
    <div>
      {state.fields
       ->switchArray(1)
       ->Array.mapWithIndex((index, element) =>
           <button onClick={_ => dispatch(Mark(1, index, element))}>
             {element == Empty
                ? ""->React.string
                : element == Cross ? "X"->React.string : "O"->React.string}
           </button>
         )
       ->React.array}
    </div>
    <div>
      {state.fields
       ->switchArray(2)
       ->Array.mapWithIndex((index, element) =>
           <button onClick={_ => dispatch(Mark(2, index, element))}>
             {element == Empty
                ? ""->React.string
                : element == Cross ? "X"->React.string : "O"->React.string}
           </button>
         )
       ->React.array}
    </div>
  </main>;
};