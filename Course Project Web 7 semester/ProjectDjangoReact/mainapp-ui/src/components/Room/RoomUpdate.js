import React, { useEffect, useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';
import { useParams } from "react-router-dom";


function RoomUpdate() {
  const [setRoom] = useState([])
  const [name, setName] = useState("");
  const [floor, setFloor] = useState("");
  const [number, setNumber] = useState("");
  const [RoomId,setRoomId]=useState(null)

  const { id } = useParams();

  useEffect(() => {
    getRooms();
  },[])

  function getRooms() {
    fetch(`http://127.0.0.1:8000/api/v1/rooms/${id}/`).then((result) => {
      result.json().then((resp) => {
        console.warn(resp)
        setRoom(resp)
        setName(resp.name)
        setFloor(resp.floor)
        setNumber(resp.number)
        setRoomId(resp.id)
      })
    })
  }

  function updateRoom()
  {
    let room = { name, floor, number }
    //console.warn("room", room)
    fetch(`http://127.0.0.1:8000/api/v1/rooms/${RoomId}/`, {
      method: 'PATCH',
      headers:{
        'Accept':'application/json',
        'Content-Type':'application/json'
      },
      redirect: "follow",
      body:JSON.stringify(room)
    }).then((result) => {
      result.json().then((resp) => {
        console.warn(resp)
        getRooms()
      })
    })
  }
  return (
    <div className="row">
            <div className="col-md-12">
                <div className="card card-body">
                    <h5>Обновите данные о помещении:</h5>
                        <br/>
                            <div>
                              <label>Название: <input type="text" value={name} onChange={(e)=>{setName(e.target.value)}} /></label> <br /><br />
                              <label>Этаж: <input type="text" value={floor} onChange={(e)=>{setFloor(e.target.value)}} /></label> <br /><br />
                              <label>Номер: <input type="text" value={number}  onChange={(e)=>{setNumber(e.target.value)}} /></label> <br /><br />
                              <button className="btn btn-sm btn-outline-info" onClick={updateRoom} >Обновить данные о помещении</button>
                            </div>
                </div>
            </div>
        </div>
  );
}

export default RoomUpdate;