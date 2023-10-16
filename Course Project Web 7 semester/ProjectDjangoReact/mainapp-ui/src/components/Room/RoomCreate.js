import React, { useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';

function RoomCreate() {
  const [name, setName] = useState("");
  const [floor, setFloor] = useState("");
  const [number, setNumber] = useState("");


  const handleSubmit = (e) => {
    e.preventDefault();
    const room = { name, floor, number };

    fetch('http://127.0.0.1:8000/api/v1/rooms/', {
      method: 'POST',
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(room)
    }).then(() => {
      console.log('new room added');
    })
  }

  return (
    <div className="row">
            <div className="col-md-12">
                <div className="card card-body">
                    <h5>Добавить новое помещение:</h5>
                        <br/>
                            <div>
                              <form onSubmit={handleSubmit}>
                                <label>Название:</label>
                                <input
                                  type="text"
                                  required
                                  value={name}
                                  onChange={(e) => setName(e.target.value)}
                                /> <br /><br />

                                <label>Этаж:</label>
                                <input
                                  type="number"
                                  required
                                  value={floor}
                                  onChange={(e) => setFloor(e.target.value)}
                                /> <br /><br />

                                <label>Номер:</label>
                                <input
                                  type="number"
                                  required
                                  value={number}
                                  onChange={(e) => setNumber(e.target.value)}
                                /> <br /><br />

                                <button className="btn btn-sm btn-outline-info">Добавить помещение</button>
                              </form>
                            </div>
                </div>
            </div>
    </div>
  );

}

export default RoomCreate;