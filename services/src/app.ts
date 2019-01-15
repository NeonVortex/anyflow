import * as express from "express"
import * as bodyParser from "body-parser"

const app = express()
const port = 8080
const maxdatasize = 10

const store = {
    "popoxee@hotmail.com": [
        "copied_data1",
        "http://google.com"
    ]
}

app.use(bodyParser.json())

app.all("/get", (req, resp) => {
    console.log("Received request get")
    const reqBody = req.body
    const username: string = reqBody.email
    const data: any[] = store[username]
    resp.json(data)
})

app.all("/submit", (req, resp) => {
    console.log("Received request submit")
    const reqBody = req.body
    const username: string = reqBody.email
    const data: any[] = reqBody.data
    store[username] = data.concat(store[username]).slice(0, 10)
    resp.json({"result": "success"})
})

app.listen(port, ()=> console.log(`Server started on port ${port}.`))
