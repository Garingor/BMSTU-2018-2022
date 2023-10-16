import React, { useEffect, useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';
import {Link} from "react-router-dom";

function RoomList() {
  const [rooms, setRoom] = useState([])
  const [setName] = useState("");
  const [setFloor] = useState("");
  const [setNumber] = useState("");
  const [setRoomId]=useState(null)

  useEffect(() => {
    getRooms();
  }, [])

  function getRooms() {
    fetch("http://127.0.0.1:8000/api/v1/rooms").then((result) => {
      result.json().then((resp) => {
        // console.warn(resp)
        setRoom(resp)
        setName(resp[0].name)
        setFloor(resp[0].floor)
        setNumber(resp[0].number)
        setRoomId(resp[0].id)
      })
    })
  }

  function deleteRoom(id) {
    fetch(`http://127.0.0.1:8000/api/v1/rooms/${id}`, {
      method: 'DELETE'
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
                <h5>Помещения:</h5>
                    <div className="card card-body">
                      <div className="d-grid gap-2 d-md-flex justify-content-md-end">
                        <Link className="btn btn-outline-primary" to={{pathname: `/rooms/add`, fromDashboard: false}}>Добавить новое помещение</Link>
                      </div>
                            <table className="table table-sm">
                                <tbody>
                                  <tr>
                                    <th>ID</th>
                                    <th>Название</th>
                                    <th>Этаж</th>
                                    <th>Номер</th>
                                    <th>Действия</th>
                                  </tr>
                                  {
                                    rooms.map((item, i) =>
                                      <tr key={i}>
                                        <td>{item.id}</td>
                                        <td>{item.name}</td>
                                        <td>{item.floor}</td>
                                        <td>{item.number}</td>
                                        <td>
                                          <div className="d-grid gap-2 d-md-block">
                                            <Link className="btn btn-sm btn-outline-info me-md-2" to={{pathname: `/rooms/edit/${item.id}`, fromDashboard: false}}>Обновить</Link>
                                            <button className="btn btn-sm btn-outline-danger" onClick={() => deleteRoom(item.id)}>Удалить</button>
                                          </div>
                                        </td>
                                      </tr>
                                    )
                                  }
                                </tbody>
                            </table>
                    </div>
            </div>
        </div>
  );
}

export default RoomList;