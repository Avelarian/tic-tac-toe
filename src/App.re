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
    {state.fields
     ->Array.mapWithIndex((rowIndex, rowContent) => {
         <div>
           {rowContent
            ->Array.mapWithIndex((columnIndex, columnContent) =>
                <button
                  onClick={_ =>
                    dispatch(Mark(rowIndex, columnIndex, columnContent))
                  }>
                  (
                    columnContent == Empty
                      ? "" : columnContent == Cross ? "X" : "O"
                  )
                  ->React.string
                </button>
              )
            ->React.array}
         </div>
       })
     ->React.array}
  </main>;
};