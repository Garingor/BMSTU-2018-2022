import React, { useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';

function ObjectCreate() {
  const [name, setName] = useState("");
  const [description, setDescription] = useState("");
  const [condition, setCondition] = useState("");
  const [date] = useState("");
  const [employee, setEmployee] = useState("");
  const [room, setRoom] = useState("");
  const [availability, setAvailability] = useState("");


  const handleSubmit = (e) => {
    e.preventDefault();
    const object = { name, description, condition, date, employee, room, availability  };

    fetch('http://127.0.0.1:8000/api/v1/rooms/', {
      method: 'POST',
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(object)
    }).then(() => {
      console.log('new object added');
    })
  }

  return (
    <div className="row">
            <div className="col-md-12">
                <div className="card card-body">
                    <h5>Добавить новое оборудование:</h5>
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

                                <label>Описание:</label>
                                <input
                                  type="text"
                                  required
                                  value={description}
                                  onChange={(e) => setDescription(e.target.value)}
                                /> <br /><br />

                                <label>Состояние:</label>
                                <select
                                  value={condition}
                                  onChange={(e) => setCondition(e.target.value)}
                                >
                                  <option value="новый">новый</option>
                                  <option value="б/у">б/у</option>
                                </select><br /><br />

                                <label>Дата внесения:(автоматически)</label><br /><br />

                                <label>Кто использует:</label>
                                <input
                                  type="text"
                                  required
                                  value={employee}
                                  onChange={(e) => setEmployee(e.target.value)}
                                /> <br /><br />

                                <label>Где оборудование:</label>
                                <input
                                  type="text"
                                  required
                                  value={room}
                                  onChange={(e) => setRoom(e.target.value)}
                                /> <br /><br />

                                <label>Доступность:</label>
                                <select
                                  value={availability}
                                  onChange={(e) => setAvailability(e.target.value)}
                                >
                                  <option value="1">доступен</option>
                                  <option value="0">не доступен</option>
                                </select><br /><br />

                                <button className="btn btn-sm btn-outline-info">Добавить оборудование</button>
                              </form>
                            </div>
                </div>
            </div>
    </div>
  );

}

export default ObjectCreate;