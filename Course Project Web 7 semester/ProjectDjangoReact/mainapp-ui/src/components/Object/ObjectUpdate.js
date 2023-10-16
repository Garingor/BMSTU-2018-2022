import React, { useEffect, useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';
import { useParams } from "react-router-dom";


function ObjectUpdate() {
  const [setObject] = useState([])
  const [name, setName] = useState("");
  const [description, setDescription] = useState("");
  const [condition, setCondition] = useState("");
  const [date, setDate] = useState("");
  const [employee, setEmployee] = useState("");
  const [room, setRoom] = useState("");
  const [availability, setAvailability] = useState("");
  const [ObjectId,setObjectId]=useState(null)

  const { id } = useParams();

  useEffect(() => {
    getObjects();
  },[])

  function getObjects() {
    fetch(`http://127.0.0.1:8000/api/v1/objects/${id}/`).then((result) => {
      result.json().then((resp) => {
        console.warn(resp)
        setObject(resp)
        setName(resp.name)
        setDescription(resp.description)
        setCondition(resp.condition)
        setDate(resp.date)
        setEmployee(resp.employee)
        setRoom(resp.room)
        setAvailability(resp.availability)
        setObjectId(resp.id)
      })
    })
  }

  function updateObject()
  {
    let object = { name, description, condition, date, employee, room, availability  }
    //console.warn("item",item)
    fetch(`http://127.0.0.1:8000/api/v1/objects/${ObjectId}/`, {
      method: 'PUT',
      headers:{
        'Accept':'application/json',
        'Content-Type':'application/json'
      },
      redirect: "follow",
      body:JSON.stringify(object)
    }).then((result) => {
      result.json().then((resp) => {
        console.warn(resp)
        getObjects()
      })
    })
  }
  return (
    <div className="row">
            <div className="col-md-12">
                <div className="card card-body">
                    <h5>Обновите данные об оборудовании:</h5>
                        <br/>
                            <div>
                              <label>Название: <input type="text" value={name} onChange={(e)=>{setName(e.target.value)}} /></label> <br /><br />
                              <label>Описание: <input type="text" value={description} onChange={(e)=>{setDescription(e.target.value)}} /></label> <br /><br />
                              <label>Состояние: <input type="text" value={condition}  onChange={(e)=>{setCondition(e.target.value)}} /></label> <br /><br />
                              <label>Дата внесения: <input type="text" value={date}  onChange={(e)=>{setDate(e.target.value)}} /></label> <br /><br />
                              <label>Кто использует: <input type="text" value={employee}  onChange={(e)=>{setEmployee(e.target.value)}} /></label> <br /><br />
                              <label>Где оборудование: <input type="text" value={room}  onChange={(e)=>{setRoom(e.target.value)}} /></label> <br /><br />
                              <label>Доступность: <input type="text" value={availability}  onChange={(e)=>{setAvailability(e.target.value)}} /></label> <br /><br />
                              <button className="btn btn-sm btn-outline-info" onClick={updateObject} >Обновить данные об оборудование</button>
                            </div>
                </div>
            </div>
        </div>
  );
}

export default ObjectUpdate;