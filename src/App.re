[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(TicTacToe.reducer, TicTacToe.initialState);

  React.useEffect1(
    () => {
      dispatch(Finish);
      None;
    },
    state.fields,
  );

  <main>
    (
      switch (state.status) {
      | Active => "Tic Tac Toe"
      | Finished => "Finished"
      }
    )
    ->React.string
    {state.fields
     ->Array.mapWithIndex((rowIndex, rowContent) => {
         <div>
           {rowContent
            ->Array.mapWithIndex((columnIndex, columnContent) =>
                <button onClick={_ => dispatch(Mark(rowIndex, columnIndex))}>
                  (
                    switch (columnContent) {
                    | Some(Cross) => "X"
                    | Some(Circle) => "O"
                    | None => ""
                    }
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