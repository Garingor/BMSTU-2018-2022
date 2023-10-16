import React, { useEffect, useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';
import {Link} from "react-router-dom";

function EmployeeList() {
  const [employees, setEmployee] = useState([])
  const [setName] = useState("");
  const [setSurname] = useState("");
  const [setPatronymic] = useState("");
  const [setAddress] = useState("");
  const [setInn] = useState("");
  const [setSeriesPassport] = useState("");
  const [setNumberPassport] = useState("");
  const [setPosition] = useState("");
  const [setLegalEntity] = useState("");
  const [setEmployeeId]=useState(null)

  useEffect(() => {
    getEmployees();
  }, [])

  function getEmployees() {
    fetch("http://127.0.0.1:8000/api/v1/employees").then((result) => {
      result.json().then((resp) => {
        // console.warn(resp)
        setEmployee(resp)
        setName(resp[0].name)
        setSurname(resp[0].surname)
        setPatronymic(resp[0].patronymic)
        setAddress(resp[0].address)
        setInn(resp[0].inn)
        setSeriesPassport(resp[0].seriespassport)
        setNumberPassport(resp[0].numberpassport)
        setPosition(resp[0].position)
        setLegalEntity(resp[0].legalentity)
        setEmployeeId(resp[0].id)
      })
    })
  }

  function deleteEmployee(id) {
    fetch(`http://127.0.0.1:8000/api/v1/employees/${id}`, {
      method: 'DELETE'
    }).then((result) => {
      result.json().then((resp) => {
        console.warn(resp)
        getEmployees()
      })
    })
  }

  return (
    <div className="row">
            <div className="col-md-12">
                <h5>Сотрудники:</h5>
                    <div className="card card-body">
                      <div className="d-grid gap-2 d-md-flex justify-content-md-end">
                        <Link className="btn btn-outline-primary" to={{pathname: `/employees/add`, fromDashboard: false}}>Добавить нового сотрудника</Link>
                      </div>
                            <table className="table table-sm">
                                <tbody>
                                  <tr>
                                    <th>ID</th>
                                    <th>Имя</th>
                                    <th>Фамилия</th>
                                    <th>Отчество</th>
                                    <th>Адрес</th>
                                    <th>ИНН</th>
                                    <th>Серия паспорта</th>
                                    <th>Номер паспорта</th>
                                    <th>Должность</th>
                                    <th>Начальник</th>
                                  </tr>
                                  {
                                    employees.map((item, i) =>
                                      <tr key={i}>
                                        <td>{item.id}</td>
                                        <td>{item.name}</td>
                                        <td>{item.surname}</td>
                                        <td>{item.patronymic}</td>
                                        <td>{item.address}</td>
                                        <td>{item.inn}</td>
                                        <td>{item.seriespassport}</td>
                                        <td>{item.numberpassport}</td>
                                        <td>{item.position}</td>
                                        <td>{item.legalentity}</td>
                                        <td>
                                          <div className="d-grid gap-2 d-md-block">
                                            <Link className="btn btn-sm btn-outline-info me-md-2" to={{pathname: `/employees/edit/${item.id}`, fromDashboard: false}}>Обновить</Link>
                                            <button className="btn btn-sm btn-outline-danger" onClick={() => deleteEmployee(item.id)}>Удалить</button>
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

export default EmployeeList;