type fieldState = 
  | Empty
  | Cross
  | Circle;

type field = {
  id: int,
  state: fieldState
}

type action =
  | Mark(field)
  | Nothing;

let nextTurn = ref(Cross);

let id = ref(0);

let initialState = { id: 0, state: Empty };

let fields = [|
{
  id: 1,
  state: Empty
},
{
  id: 2,
  state: Empty
},
{
  id: 3,
  state: Empty
},
{
  id: 4,
  state: Empty
},
{
  id: 5,
  state: Empty
},
{
  id: 6,
  state: Empty
},
{
  id: 7,
  state: Empty
},
{
  id: 8,
  state: Empty
},
{
  id: 9,
  state: Empty
},
|];

/* State transitions */
let reducer = (state, action) => {
  state->Belt.Array.map(s => {
    switch (action) {
      | Mark(field) => {
        field.id == s.id ? { nextTurn := nextTurn^ == Cross ? Circle : Cross; { ...s, state: nextTurn^}; } : s;
      }
      | Nothing => s;
  }});
};

// let updateField = (field) => {
//   id := id^ + 1;
//   { id: id^, state: nextTurn^ }
// }; nextTurn^ == Cross ? Circle : Cross; Js.log(nextTurn); updateField(field);

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, fields);

  let toMark = (field) => {
    field.state == Empty ?
     { Js.log(state); dispatch(Mark(field)); } :
     { Js.log(state); dispatch(Nothing) };
    
  };

  // let winner = () => {
  //   if (state[0] == Cross && state)
  // }

  <main>
    {React.string("Simple tic-tac-toe with reducer")}
    <div>
      <button onClick={_ => toMark(state[0])}>
        {state[0].state == Empty ? ""->React.string : (state[0].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => toMark(state[1])}>
        {state[1].state == Empty ? ""->React.string : (state[1].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => toMark(state[2])}>
        {state[2].state == Empty ? ""->React.string : (state[2].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
    </div>
    <div>
      <button onClick={_ => toMark(state[3])}>
        {state[3].state == Empty ? ""->React.string : (state[3].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => toMark(state[4])}>
        {state[4].state == Empty ? ""->React.string : (state[4].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => toMark(state[5])}>
        {state[5].state == Empty ? ""->React.string : (state[5].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
    </div>
    <div>
      <button onClick={_ => toMark(state[6])}>
        {state[6].state == Empty ? ""->React.string : (state[6].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => toMark(state[7])}>
        {state[7].state == Empty ? ""->React.string : (state[7].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
      <button onClick={_ => toMark(state[8])}>
        {state[8].state == Empty ? ""->React.string : (state[8].state == Cross ? "X"->React.string : "O"->React.string)}
      </button>
    </div>
  </main>;
};
