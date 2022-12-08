import React, { useEffect, useState } from "react";
import 'bootstrap/dist/css/bootstrap.min.css';
import { useParams } from "react-router-dom";


function LegalEntityUpdate() {
  const [setLegalEntity] = useState([])
  const [name, setName] = useState("");
  const [surname, setSurname] = useState("");
  const [patronymic, setPatronymic] = useState("");
  const [address, setAddress] = useState("");
  const [inn, setInn] = useState("");
  const [seriespassport, setSeriesPassport] = useState("");
  const [numberpassport, setNumberPassport] = useState("");
  const [employeenumber, setEmployeeNumber] = useState("");
  const [LegalEntityId,setLegalEntityId]=useState(null)

  const { id } = useParams();

  useEffect(() => {
    getLegalEntities();
  },[])

  function getLegalEntities() {
    fetch(`http://127.0.0.1:8000/api/v1/legalentities/${id}/`).then((result) => {
      result.json().then((resp) => {
        console.warn(resp)
        setLegalEntity(resp)
        setName(resp[0].name)
        setSurname(resp[0].surname)
        setPatronymic(resp[0].patronymic)
        setAddress(resp[0].address)
        setInn(resp[0].inn)
        setSeriesPassport(resp[0].seriespassport)
        setNumberPassport(resp[0].numberpassport)
        setEmployeeNumber(resp[0].employeenumber)
        setLegalEntityId(resp[0].id)
      })
    })
  }

  function updateLegalEntity()
  {
    let legalentity = { name, surname, patronymic, address, inn, seriespassport, numberpassport, employeenumber };
    //console.warn("legalentity", legalentity)
    fetch(`http://127.0.0.1:8000/api/v1/legalentities/${LegalEntityId}/`, {
      method: 'PUT',
      headers:{
        'Accept':'application/json',
        'Content-Type':'application/json'
      },
      redirect: "follow",
      body:JSON.stringify(legalentity)
    }).then((result) => {
      result.json().then((resp) => {
        console.warn(resp)
        getLegalEntities()
      })
    })
  }
  return (
    <div className="row">
            <div className="col-md-12">
                <div className="card card-body">
                    <h5>Обновите данные об юридическом лице:</h5>
                        <br/>
                            <div>
                              <label>Имя: <input type="text" value={name} onChange={(e)=>{setName(e.target.value)}} /></label> <br /><br />
                              <label>Фамилия: <input type="text" value={surname} onChange={(e)=>{setSurname(e.target.value)}} /></label> <br /><br />
                              <label>Отчество: <input type="text" value={patronymic}  onChange={(e)=>{setPatronymic(e.target.value)}} /></label> <br /><br />
                              <label>Адрес: <input type="text" value={address}  onChange={(e)=>{setAddress(e.target.value)}} /></label> <br /><br />
                              <label>ИНН: <input type="text" value={inn}  onChange={(e)=>{setInn(e.target.value)}} /></label> <br /><br />
                              <label>Серия паспорта: <input type="text" value={seriespassport}  onChange={(e)=>{setSeriesPassport(e.target.value)}} /></label> <br /><br />
                              <label>Номер паспорта: <input type="text" value={numberpassport}  onChange={(e)=>{setNumberPassport(e.target.value)}} /></label> <br /><br />
                              <label>Кол-во подчиненныхы: <input type="text" value={employeenumber}  onChange={(e)=>{setEmployeeNumber(e.target.value)}} /></label> <br /><br />
                              <button className="btn btn-sm btn-outline-info" onClick={updateLegalEntity } >Обновить данные об юридическом лице</button>
                            </div>
                </div>
            </div>
        </div>
  );
}

export default LegalEntityUpdate;