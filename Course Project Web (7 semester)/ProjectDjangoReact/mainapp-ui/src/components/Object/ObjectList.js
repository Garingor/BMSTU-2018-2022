import React, { useEffect, useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';
import {Link} from "react-router-dom";

function ObjectList() {
  const [objects, setObject] = useState([])
  const [setName] = useState("");
  const [setDescription] = useState("");
  const [setCondition] = useState("");
  const [setDate] = useState("");
  const [setEmployee] = useState("");
  const [setRoom] = useState("");
  const [setAvailability] = useState("");
  const [setObjectId]=useState(null)

  useEffect(() => {
    getObjects();
  },[])

  function getObjects() {
    fetch(`http://127.0.0.1:8000/api/v1/objects`).then((result) => {
      result.json().then((resp) => {
        //console.warn(resp)
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

  function deleteObject(id) {
    fetch(`http://127.0.0.1:8000/api/v1/objects/${id}`, {
      method: 'DELETE'
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
                <h5>Оборудование:</h5>
                    <div className="card card-body">
                      <div className="d-grid gap-2 d-md-flex justify-content-md-end">
                        <Link className="btn btn-outline-primary" to={{pathname: `/objects/add`, fromDashboard: false}}>Добавить новое оборудование</Link>
                      </div>
                            <table className="table table-sm">
                                <tbody>
                                  <tr>
                                    <th>ID</th>
                                    <th>Название</th>
                                    <th>Описание</th>
                                    <th>Состояние</th>
                                    <th>Дата внесения</th>
                                    <th>Кто использует</th>
                                    <th>Где оборудование</th>
                                    <th>Доступность</th>
                                  </tr>
                                  {
                                    objects.map((item, i) =>
                                      <tr key={i}>
                                        <td>{item.id}</td>
                                        <td>{item.name}</td>
                                        <td>{item.description}</td>
                                        <td>{item.condition}</td>
                                        <td>{item.date}</td>
                                        <td>{item.employee}</td>
                                        <td>{item.room}</td>
                                        <td>{item.availability}</td>
                                        <td>
                                          <div className="d-grid gap-2 d-md-block">
                                            <Link className="btn btn-sm btn-outline-info me-md-2" to={{pathname: `/objects/edit/${item.id}`, fromDashboard: false}}>Обновить</Link>
                                            <button className="btn btn-sm btn-outline-danger" onClick={() => deleteObject(item.id)}>Удалить</button>
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

export default ObjectList;